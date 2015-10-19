/*

    Author:				    David Bartholomew
    Date Created:			10/09/15
    Class information:		CST 211; Joshua Kimball
    Filename:				node.h

    Overview: header file for linked list node code

    Input: no inputs
    
    Output: no outputs
      
*/


template <class T>
class Node
{
        public:
            Node();
            ~Node();
            Node(Node<T>& aNode);
            
            Node<T>& operator=(const Node<T> & rhs);

        private:
            T m_data;
            Node<T> *m_next;
            Node<T> *m_prev;
};

#include "node.cpp"