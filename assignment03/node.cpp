/*

    Author:				    David Bartholomew
    Date Created:			10/09/15
    Class information:		CST 211; Joshua Kimball
    Filename:				node.cpp

    Overview: functionality file for node.h header file
    - various functions for use in linked list node element
    access

    Input: no inputs
    
    Output: outputs to the console
      
*/

/*
	Purpose: Default node constructor class 
                 
    Inputs:  Instantiation of NODE object for use in two directional linked list;
    both pointers (next/prev) set to 0

    Outputs:  No return values
*/

template <class T>
Node<T>::Node()
{
        m_next = NULL;
        m_prev = NULL;
}

/*
	Purpose: Default node destructor class; no actual functionality as I never allocated memory for the default node object
                 
    Inputs:  No input values

    Outputs:  No return values
*/

template<class T>
Node<T>::~Node()
{
        
}

/*
	Purpose: overloaded assignment operator for node objects 
                 
    Inputs:  Per the UML diagram, I'm presumably expected to assign the data from node to another and return the pointer to the new node

    Outputs:  Returns a reference to a new node object now that it's got a copy of the data from the input
*/

template <class T>
Node<T>& Node<T>::operator=(const Node<T> & rhs) {
    Node<T> *output = new Node<T>;
    output->m_data = rhs->m_data;
    
    return output;
}

/*
	Purpose: Copy constructor for the node class
                 
    Inputs:  passing in a node value by reference

    Outputs:  No return values; a new node object is constructed
*/

template <class T>
Node<T>::Node(Node<T>& aNode) {
    Node<T> *output = new Node<T>;
    output->m_next = aNode->m_next;
    output->m_prev = aNode->m_prev;
    
}

