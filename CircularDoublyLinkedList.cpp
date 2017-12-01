#include "CircularDoublyLinkedList.h"
#include <iostream>

using namespace std;
   
// An implementation of templated class "CircularDoublyLinkedList"

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList()
{
	CircularDoublyLinkedList(20, 4);
}

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(int size, int wS)
{
	listCapacity = size;
	wSize = wS;
	numberOfNodes = 0;
	headPosition = 0 ;
	start = nullptr;
	// fill the list
	for (int i = 0; i < size; i++) {
		insert(i, i+1);
	}
	// shuffle the list
	for (int i = 0; i < listCapacity; i++) {
		int r = rand() % listCapacity ;
		int temp = findValue(i);
		setValue(i, findValue(r));
		setValue(r, temp);
	}
}

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList()
{
	Node<T> * here = start, *nextNode;
	while (here != nullptr)
	{
		nextNode = here->getNext();
		delete here;
		here = nextNode;
	}
}

//template<class T>
//void CircularDoublyLinkedList<T>::printTape()
//{
//
//	int middle = (listCapacity ) / 2;
//
//	for (int i = headPosition  , j = 1; i < (listCapacity + headPosition ); i++, j++) {
//
//		int index = (i % listCapacity ) ;
//
//
//		int firstBracket = (middle - (wSize / 2) + 1);
//		if (j == firstBracket) {
//				cout << " [ ";
//		}
//		else if (j == firstBracket + wSize) {
//			cout << " ] ";
//		}
//
//		cout << " " << findValue(index) << " ";
//	}
//	cout << endl;
//}

template<class T>
void CircularDoublyLinkedList<T>::swap(int key1, int key2)
{
	int temp = findValue(key1);
	setValue(key1, findValue(key2));
	setValue(key2, temp);
}

template<class T>
bool CircularDoublyLinkedList<T>::isEmpty() const
{
	return (numberOfNodes == 0);

}

template<class T>
T CircularDoublyLinkedList<T>::getValue() const
{
	if (numberOfNodes != 0)
	{
		return start->getValue();
	}
	return 0;
}

template<class T>
int CircularDoublyLinkedList<T>::getKey()
{
	if (numberOfNodes != 0)
	{
		return start->getKey();
	}
	return 0;
}

template<class T>
int CircularDoublyLinkedList<T>::getBracketPosition()
{
	int step = (listCapacity / 2) - (wSize / 2);
	return  (headPosition + step) % listCapacity;

}

template<class T>
int CircularDoublyLinkedList<T>::getHeadPosition()
{

	return  headPosition ;

}

template<class T>
T CircularDoublyLinkedList<T>::findValue(int k)
{
	int value = 0;
	for (int i = 0; i < listCapacity; i++) {
		if (start->getKey() == k) {
			value = start->getValue();
			break;
		}
		start = start->getNext();
	}
	return value;
	
}

template<class T>
void CircularDoublyLinkedList<T>::setValue(int k, T val)
{
	if (numberOfNodes != 0)
	{
		for (int i = 0; i < listCapacity; i++) {
			if (start->getKey() == k) {
				start->setValue(val);
				break;
			}
			start = start->getNext();
		}
	}
}

template<class T>
void CircularDoublyLinkedList<T>::insert(unsigned int k, T data) {
	Node<T> *node = new Node<T>(k, data, nullptr, nullptr);

	if (isEmpty()) {
		start = node;
		numberOfNodes++;
	}
	else {
		Node<T> *temp = start;
		Node<T> *last = start->getPrev();

		node->setNext(temp);
		temp->setPrev(node);

		if (numberOfNodes == 1) {
			node->setPrev(temp);
			temp->setNext(node);
		}
		else {
			node->setPrev(last);
			last->setNext(node);
		}
		start = node;
		numberOfNodes++;
	}
}

template<class T>
T CircularDoublyLinkedList<T>::remove(unsigned int k)
{
	Node<T> *node = nullptr;
	int value = 0;
	if (!isEmpty()) {
		for (int i = 0; i < listCapacity; i++) {
			if (start->getKey() == k) {
				value = start->getValue();
				node = start;
				break;
			}
			start = start->getNext();
		}

		Node<T> *p = node->getPrev();
		Node<T> *n = node->getNext();

		p->setNext(n);
		n->setPrev(p);
	}
	return value;
}

template<class T>
T CircularDoublyLinkedList<T>::replace(unsigned int k, T item)
{ 
	int value = findValue(k);
	setvalue(k, T);
	return value;
}

template<class T>
void CircularDoublyLinkedList<T>::stepRight() {
	if (!isEmpty())
	{
		start = start->getPrev();
		if (headPosition == 0)
			headPosition = listCapacity-1;

		else
			headPosition--;

	}
}

template<class T>
void CircularDoublyLinkedList<T>::stepLeft() {
	if (!isEmpty())
	{

		start = start->getNext();
		if (headPosition == listCapacity-1)
			headPosition = 0;

		else
			headPosition++;
	}
}

template<class T>
unsigned int CircularDoublyLinkedList<T>::size() const
{
	return listCapacity;
}