/*

    Author:				    David Bartholomew
    Date Created:			10/09/15
    Class information:		CST 211; Joshua Kimball
    Filename:				linkedlist.h

    Overview: header file for linked list code

    Input: no specific inputs
    
    Output: no specific outputs
      
*/

template <class T>
class LinkedList
{
        public:
            LinkedList();
            ~LinkedList();
            LinkedList(const LinkedList<T>& aList);
            
            LinkedList<T>& operator=(const LinkedList<T> & rhs);

            bool isEmpty();
            
            const Node<T>& First();
            const Node<T>& Last();
            void Prepend(T* input);
            void Append(T* input);
            void Purge();
            Node<T>& Extract(T input);
            void InsertAfter(T input, T* inputPtr);
            void InsertBefore(T input, T* inputPtr);
 //           Iterator Begin();
 //           Iterator End();
            
        private:
            Node<T> *m_tail;
            Node<T> *m_head;
   
};

#include "linkedlist.cpp"