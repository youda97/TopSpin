#pragma once
#include "Node.cpp"
template <class T>

class CircularDoublyLinkedList {

public:
	CircularDoublyLinkedList(); // construct an empty circular doubly linked list
	CircularDoublyLinkedList(int size, int wS); //constructor with parameters

	~CircularDoublyLinkedList(); // destroy a circular doubly linked list

	unsigned int size() const; // return number of items in the list

	void insert(unsigned int k, T value); // Add a new node containing an item in position k on the list
	bool isEmpty() const; // true if list is empty, false otherwise
	T getValue() const; // Return the item value at the current position
	int getKey(); //return the key of the node 
	int getBracketPosition(); //returns the position of the first value in the window spinner
	int getHeadPosition(); //returns the position of the first value in the list

	T findValue(int k); //finds the value at position k 
	void setValue(int k, T val); //sets the value at position k
	T remove(unsigned int k); // Remove the node at position k from the list, and return the item it contained; 
	T replace(unsigned int k, T item); // Replace the data stored in position k of the list with item, and return the replaced item; 

	void stepRight(); //moves to the next node
	void stepLeft();//moves to the previous node
	//void printTape();

	void swap(int key1, int key2); //switches the position of two values in the list

private:
	Node<T> * start;
	int listCapacity;
	int numberOfNodes;
	int wSize;
	int headPosition;

};
