#include "Node.h"

/*
Purpose: overloaded assignment operator for node objects

Inputs:  assign the data from node to another and return the pointer to the new node

Outputs:  Returns a reference to a new node object now that it's got a copy of the data from the input
*/

template <class T>
Node<T>& Node<T>::operator= (const Node<T> & input)
{
	data = input.data;
	m_next = input.m_next;
	m_prev = input.m_prev;
	return *this;
}

/*
Purpose: Node setter function to place data into the templated node object

Inputs:  input value to jam into the node object's 'data' field

Outputs:  No return values
*/

template <class T>
void Node<T>::setData(T input) { data = input; }

/*
Purpose: Node setter function to place a pointer address into the templated node object's 'next' field

Inputs:  input value for this->m_next

Outputs:  No return values
*/

template <class T>
void Node<T>::setNext(Node<T>* input) { m_next = input; }

/*
Purpose: Node setter function to place a pointer address into the templated node object's 'previous' field

Inputs:  input value for this->m_prev

Outputs:  No return values
*/

template <class T>
void Node<T>::setPrev(Node<T>* input) { m_prev = input; }

/*
Purpose: Node getter function to return a pointer address from the templated node object's private 'data' field

Inputs:  no specific inputs

Outputs:  returns this->data
*/

template <class T>
T Node<T>::getData() { return this->data; }

/*
Purpose: Node getter function to return a pointer address from the templated node object's private 'next' field

Inputs:  no specific inputs

Outputs:  returns this->m_next
*/

template <class T>
Node<T>* Node<T>::getNext() { return this->m_next; }

/*
Purpose: Node getter function to return a pointer address from the templated node object's private 'previous' field

Inputs:  no specific inputs

Outputs:  returns this->previous
*/

template <class T>
Node<T>* Node<T>::getPrev() { return this->m_prev; }

/*
Purpose: Node default constructor function with no given parameters; sets all three items to NULL

Inputs:  no specific inputs

Outputs:  no return values
*/

template <class T>
Node<T>::Node()
{
    data = NULL;
    m_next = NULL;
    m_prev = NULL;
}

/*
Purpose: Node default constructor function with the data parameter provided; sets next/previous pointers to NULL

Inputs:  templated data value 

Outputs:  no return values
*/

template <class T>
Node<T>::Node(T input)
{
	data = input;
	m_next = NULL;
	m_prev = NULL;
}

/*
Purpose: Node default destructor function designed to clear up memory for node objects when we're exiting scope

Inputs:  no specific inputs

Outputs:  no return values
*/

template <class T>
Node<T>::~Node()
{
        if(!m_next)
            delete m_next;
        if(!m_prev)
            delete m_prev;
}
