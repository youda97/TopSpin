#include "Node.h"

// An implementation of templated class "Node"

template <class T>
 Node<T>::Node() {
	 Node(nullptr);
}
 template <class T>
 Node<T>::Node(int k, T val) {
	 Node(k, val, nullptr, nullptr);
 }
 template <class T>
 Node<T>::Node(int k, T val, Node * p, Node * n) {
	 value = val;
	 key = k;
	 next = p;
	 prev = n;
 }
 template <class T>
 Node<T> * Node<T>::getNext() {
	 return next;
 }
 template <class T>
 Node<T> * Node<T>::getPrev() {
	 return prev;
 }

 template <class T>
 int Node<T>::getKey() {
	return key;
 }

 template <class T>
 T Node<T>::getValue() {
	 return value;
 }
 template <class T>
 void Node<T>::setNext(Node<T> * n) {
	 next = n;
 }
 template <class T>
 void Node<T>::setPrev(Node<T> * p) {
	 prev = p;
 }

 template <class T>
 void Node<T>::setValue(T val) {
	 value = val;
 }

 template<class T>
 Node<T>& Node<T>::operator=(const Node<T>& rhs){
	 Node<T> *copy_of_rhs = rhs;
	 std::swap(start, copt_of_rhs.start);
	 return *this;
 }

