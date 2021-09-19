#include "Node.h"
#include <string>
template<class T>
Node<T>::Node(T value) {this->value = value;}

template<class T>
Node<T>* Node<T>::getNext() {return next;}

template<class T>
T& Node<T>::getValue() {return value;}

template<class T>
void Node<T>::setNext(Node<T>* node) {next = node;}

template<class T>
void Node<T>::setValue(T value) {this->value = value;}

