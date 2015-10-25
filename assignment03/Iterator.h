/*

Author:				    David Bartholomew
Date Created:			10/24/15
Class information:		CST 211; Joshua Kimball
Filename:				iterator.h

Overview: header file for linked list iterator code; primarily used for traversing linked lists and providing an
		interface to allow programmers to get at the beginning and ends of the linked list

Input: no inputs

Output: no outputs

*/


#ifndef Iterator_H
#define Iterator_H

#include <iostream>
#include "Node.h"

template <class T>
class Iterator
{
	public:
		Iterator();
		Iterator(Node<T>* aNode);
		~Iterator();

		Iterator<T> operator++(int);
		Iterator<T> operator++();
		Iterator<T> operator--(int);
		Iterator<T> operator--();

		Iterator<T>& operator= (const Iterator<T> & input);

		Node<T>* getNode();

	private:
		Node<T>* m_node;
};

#include "Iterator.inc"
#endif