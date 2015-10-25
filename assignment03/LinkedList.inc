#include "LinkedList.h"

/*
Purpose: Linked list 'copy constructor' function; supposed to read through the list -> find a value -> insert before the matching entry

Inputs:  input value to search for, and a pointer to insert into the list

Outputs:  No return values
*/

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	Node<T>* current = rhs.m_head;

	if (rhs.m_head != NULL) 
	{
		m_head = new Node<T>;
		m_head->setData(current->getData());

		Node<T>* shadow = m_head;
		while (current->getNext())
		{
			shadow->setNext(new Node<T>(current->getNext()->getData()));
			shadow = shadow->getNext();
			current = current->getNext();
		}
	}
}

/*
Purpose: Linked list overloaded assignment operator

Inputs:  passing in a linked list to  assign it to a second, target list

Outputs:  returns a reference to the left hand side version of the two linked list items being assigned
*/

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & rhs)
{

	Node<T>* current = rhs.m_head;
	Purge();

	if (rhs.m_head != NULL) //then we're starting with an empty ll as the destination
	{

		m_head = new Node<T>;
		m_head->setData(current->getData());

		Node<T>* shadow = m_head;
		while (current->getNext())
		{
			shadow->setNext(new Node<T>(current->getNext()->getData()));
			shadow = shadow->getNext();
			current = current->getNext();
		}
	}
	return *this;
}

/*
Purpose: Linked list 'compare and insert' function; supposed to read through the list -> find a value -> insert before the matching entry

Inputs:  input value to search for, and a pointer to insert into the list

Outputs:  No return values
*/

template <class T>
void LinkedList<T>::InsertBefore(T input, T* inputPtr)
{
	Node<T> *current = m_head;
	while (current)
	{
		if (current->getData() == input)
		{
			Node<T> *p = current->getPrev();
			p->setNext(inputPtr);
			inputPtr->setPrev(p);
			inputPtr->setNext(current);
			current->setPrev(inputPtr);
			current = m_tail;
		}
		else
		{
			current = current->getNext();
		}
	}
}

/*
Purpose: Linked list 'compare and insert' function; supposed to read through the list -> find a value -> insert after the matching entry

Inputs:  input value to search for, and a pointer to insert into the list

Outputs:  No return values
*/

template <class T>
void LinkedList<T>::InsertAfter(T input, T* inputPtr)
{
	Node<T> *current = m_head;
	while (current)
	{
		if (current->getData() == input)
		{
			Node<T> *p = current->getNext();
			current->setNext(inputPtr);
			inputPtr->setPrev(current);
			inputPtr->setNext(p);
			p->setPrev(inputPtr);
			current = m_tail;
		}
		else
		{
			current = current->getNext();
		}
	}
}

/*
Purpose: Designed to simply pull the input data's value out of the list

Inputs:  input value to compare against linked list items

Outputs:  linked list node object reference matching the input parameter
*/

template <class T>
Node<T>& LinkedList<T>::Extract(T input)
{
	Node<T> *current = m_head;
	Node<T> *r = NULL;
	while (current)
	{
		if (current->getData() == input)
		{
			Node<T> *p = current->getPrev();
			Node<T> *q = current->getNext();
			r = current;
			p->setNext(current->getNext()); //this rips the current one right out of the list
			q->setPrev(p);
			current = m_tail;
		}
		else
		{
			current = current->getNext();
		}
	}
	return *r;
}

/*
Purpose: general 'getter' function to return the 'head' portion of the linked list

Inputs:  no specific inputs

Outputs:  returns 'm_head' (list header) value
*/

template <class T>
const Node<T>& LinkedList<T>::First() { return *m_head; }

/*
Purpose: general 'getter' function to return the 'tail' portion of the linked list

Inputs:  no specific inputs

Outputs:  returns 'm_tail' (list footer) value
*/

template <class T>
const Node<T>& LinkedList<T>::Last() { return *m_tail; }

/*
Purpose: function to create an iterator object for the beginning of the linked list

Inputs:  no specific inputs

Outputs:  returns 'm_begin' object for use in traversing a list from the start
*/

template <class T>
Iterator<T> LinkedList<T>::Begin()
{
	Iterator<T> m_begin(m_head);
	return m_begin;
}

/*
Purpose: function to create an iterator object for the end of the linked list

Inputs:  no specific inputs

Outputs:  returns 'm_end' object for use in traversing a list backwards from the end
*/

template <class T>
Iterator<T> LinkedList<T>::End()
{
	Iterator<T> m_end(m_tail);

	return m_end;
}

/*
Purpose: function to traverse the list, deleting all node objects, clearing up allocated memory

Inputs:  no specific inputs

Outputs:  no specific outputs
*/

template <class T>
void LinkedList<T>::Purge()
{
	Node<T> *current = m_head;
	while (current)
	{
		current = current->getNext();
		delete m_head;
		m_head = current;
	}

	delete m_head;

	m_head = NULL;
	m_tail = NULL;
}

/*
Purpose: Prepend function; designed to take a linked list node item and place it on the front of the list, shifting the 'head' forward to match

Inputs:  Node object to jam onto the front of the list

Outputs:  No return values
*/

template <class T>
void LinkedList<T>::Prepend(T* input)
{
	Node<T> *current = new Node<T>(*input);
	if ((!m_head) && (!m_tail))
	{
		m_head = current;
		m_tail = current;
	}
	else {
		current->setNext(m_head);
		current->setPrev(NULL);
		m_head = current;
	}
}

/*
Purpose: Append function; designed to take a linked list node item and place it at the end of the list, shifting the 'tail' down to match

Inputs:  Node object to place at the end of the list

Outputs:  No return values
*/

template <class T>
void LinkedList<T>::Append(T *input)
{
	Node<T> *current = new Node<T>(*input);
	if ((!m_head) && (!m_tail))
	{
		m_head = current;
		m_tail = current;
	}
	else {

		current->setPrev(m_tail);
		current->setNext(NULL);
		m_tail->setNext(current);
		m_tail = current;
	}
}

/*
Purpose: boolean function to determine if the list is empty or not by returning the state of the 'm_head' variable

Inputs:  no specific inputs

Outputs:  returns boolean output (true if m_head is empty, false if it's not)
*/

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (m_head == NULL);
}

/*
Purpose: default constructor for linked list with no inputs; sets the two values (head and tail) to null values

Inputs:  no specific inputs

Outputs:  no returns
*/

template <class T>
LinkedList<T>::LinkedList() { m_head = NULL; m_tail = NULL; }

/*
Purpose: default constructor for linked list; sets the two values (head and tail) to the provided input pointer

Inputs:  pointer to the provided input

Outputs:  no returns
*/

template <class T>
LinkedList<T>::LinkedList(Node<T> * input)
{
	m_head = input;
	m_tail = input;
}

/*
Purpose: default destructor for the linked list object class; designed to traverse to clear up the allocated memory

Inputs:  no specific inputs

Outputs:  no outputs
*/

template <class T>
LinkedList<T>::~LinkedList()
{
/*	Node<T> *current = m_head;
	while (current)
	{
		current = current->getNext();
		delete m_head;
		m_head = current;
	}

	delete m_head;
	if(!m_tail)
		delete m_tail;

	m_head = NULL;
	m_tail = NULL; */
	Purge();
}
