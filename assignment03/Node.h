/*

Author:				    David Bartholomew
Date Created:			10/24/15
Class information:		CST 211; Joshua Kimball
Filename:				node.h

Overview: header file for linked list node code

Input: no inputs

Output: no outputs

*/


#ifndef Node_H
#define Node_H

#include <iostream>

template <class T>
class Node {
public:
	Node();
	Node(T input);
	~Node();

	T getData();
	Node<T>* getNext();
	Node<T>* getPrev();
	void setData(T input);
	void setNext(Node<T>* input);
	void setPrev(Node<T>* input);

	Node<T>& operator= (const Node<T> & input);

private:
	T data;
	Node<T> *m_next;
	Node<T> *m_prev;
};

#include "Node.inc"

#endif