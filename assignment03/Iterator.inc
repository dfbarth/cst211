#include "Iterator.h"

/*
Purpose: Overloaded assignment operator for use with iterator objects, allowing one to be set to another

Inputs:  right hand value to pipe into instance of iterator object

Outputs:  returns modified iterator object by reference
*/

template <class T>
Iterator<T>& Iterator<T>::operator= (const Iterator<T> & input)
{
	m_node = input.m_node;
	return *this;
}

/*
Purpose: Iterator default constructor function with no given parameters; sets node pointer to NULL

Inputs:  no specific inputs

Outputs:  no return values
*/

template <class T>
Iterator<T>::Iterator()
{
	m_node = NULL;		
}

/*
Purpose: Iterator default constructor function; takes a pointer as input to use as the 'starting point' - not necessarily
		the beginning of the list

Inputs:  Templated node object pointer

Outputs:  no return values
*/

template <class T>
Iterator<T>::Iterator(Node<T>* aNode)
{
	m_node = aNode;
}

/*
Purpose: Iterator default destructor function designed to clean up allocated memory; no actual function in this application

Inputs:  no specific inputs

Outputs:  no return values
*/

template<class T>
Iterator<T>::~Iterator() {} //sir destructor not appearing in this film

/*
Purpose: Iterator overloaded postfix incrementor operator; meant to operate as follows: iterator++

Inputs:  an iterator object with the operator placed on the 'right' side

Outputs:  returns pointer to the current item in the linked list, but moves the iterator forward to the next location
*/

template<class T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> tempy(m_node);
	m_node = m_node->getNext();
	return tempy;
}

/*
Purpose: Iterator overloaded prefix incrementor operator; meant to operate as follows: ++iterator

Inputs:  an iterator object with the operator placed on the 'left' side

Outputs:  returns pointer to the next item in the linked list
*/

template<class T>
Iterator<T> Iterator<T>::operator++()
{
	m_node = m_node->getNext();
	return *this;
}

/*
Purpose: Iterator overloaded postfix decrementor operator; meant to operate as follows: iterator--

Inputs:  an iterator object with the operator placed on the 'right' side

Outputs:  returns pointer to the current item in the linked list, but moves the iterator backwards to the previous location
*/


template<class T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> tempy(m_node);
	m_node = m_node->getPrev();
	return tempy;
}

/*
Purpose: Iterator overloaded prefix decrementor operator; meant to operate as follows: --iterator

Inputs:  an iterator object with the operator placed on the 'left' side

Outputs:  returns pointer to the previous item in the linked list
*/


template<class T>
Iterator<T> Iterator<T>::operator--()
{
	m_node = m_node->getPrev();
	return *this;
}

/*
Purpose: Iterator getter function; allows the system to get at the node inside an iterator object

Inputs: no specific inputs

Outputs:  returns pointer to current node in the iterator (without changing its position)
*/

template <class T>
Node<T>* Iterator<T>::getNode() { return m_node; }
