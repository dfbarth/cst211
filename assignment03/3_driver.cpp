/*

    Author:				    David Bartholomew
    Date Created:			10/18/15
    Class information:		CST 211; Joshua Kimball
    Filename:				driver.cpp

    Overview: testing file for assignment 3; designed to 
    demonstrate a working iterator and linked list system
    : at this time, no iterator functionality has been implemented
    : this file is for all intents and purposes a placeholder until
    : I learn more about these concepts and can implement them more
    : completely;
    
    TODO:
    - learn how to properly access the linked list nodes to add data to them
    - learn more about overloading operators
    - learn more about pointers

    Input: no inputs
    
    Output: outputs to the console
      
*/

#include <iostream>
#include "node.h"
#include "linkedlist.h"

template<class T>
class Iterator
{
        public:
            Iterator();
            ~Iterator();
            /*

            Iterator& Iterator(Iterator& const aIterator);
            Iterator& operator=(const Iterator & rhs);

            Iterator operator++();
            Iterator operator++(int);
            
            Iterator operator--();
            Iterator operator--(int);
            */
        private:
            Node<T> *m_node;
};

template<class T>
Iterator<T>::Iterator()
{
    m_node = NULL;
}

template<class T>
Iterator<T>::~Iterator()
{
        if(m_node != NULL)
            delete[] m_node;
}

int main()
{

    return 0;
    
}