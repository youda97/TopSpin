#pragma once
template <class T>

class Node {  // circular doubly linked list nodes (basic containers of a linked list)  

public:
	Node();
	Node(int k, T val);
	Node(int k, T val, Node * p, Node * n);

	Node<T> * getNext();
	Node<T> * getPrev();
	T getValue();
	void setValue(T val);
	int getKey();

	void setNext(Node<T> * n);
	void setPrev(Node<T> * p);

private :
	int key;
	T  value;
	Node<T> * next;
	Node<T> * prev;
	Node<T>& operator =(const Node<T>&);
};