/*

Author:				    David Bartholomew
Date Created:			10/24/15
Class information:		CST 211; Joshua Kimball
Filename:				linkedlist.h

Overview: header file for linked list code; collection of LinkedList protoypes

Input: no specific inputs

Output: no specific outputs

*/

#ifndef LinkedList_H
#define LinkedList_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(Node<T> * input);
	~LinkedList();

	LinkedList(const LinkedList<T>& rhs);
	LinkedList<T>& operator=(const LinkedList<T> & rhs);

	bool isEmpty();
	const Node<T>& First();
	const Node<T>& Last();
	void Prepend(T* input);
	void Append(T* input);
	void InsertBefore(T input, T* inputPtr);
	void InsertAfter(T input, T* inputPtr);
	void Purge();
	Node<T>& Extract(T input);
	Iterator<T> Begin();
	Iterator<T> End();

private:
	Node<T> *m_head;
	Node<T> *m_tail;
};

#include "LinkedList.inc"
#endif