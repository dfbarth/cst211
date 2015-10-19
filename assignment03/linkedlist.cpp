/*
	Purpose: Linked list 'compare and insert' function; supposed to read through the list -> find a value -> insert after the matching entry 
                 
    Inputs:  input value to search for, and a pointer to insert into the list

    Outputs:  No return values
*/

template <class T>
void LinkedList<T>::InsertAfter(T input, T* inputPtr)
{
   		Node<T> *current = m_head;
		while (current != NULL)
		{
			Node<T> *p = current;
			current = current->m_next;
			if(current != NULL)
			{
                if(p->m_data == input)
                {
                    current->m_prev = inputPtr;
                    p->m_next = inputPtr;
                    inputPtr->m_next = current;
                    inputPtr->m_prev = p;
                    
                }
            }
        }
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
		while (current != NULL)
		{
			Node<T> *p = current;
			current = current->m_next;
			if(current != NULL)
			{
                if(current->m_data == input)
                {
                    current->m_prev = inputPtr;
                    p->m_next = inputPtr;
                    inputPtr->m_next = current;
                    inputPtr->m_prev = p;
                    
                }
            }
        }
}

/*
	Purpose: Linked list overloaded assignment operator
                 
    Inputs:  passing in a linked list to presumably assign it to a second, target list

    Outputs:  No return values
*/

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & rhs)
{
//        this->m_tail = rhs->m_tail;
//        this->m_head = rhs->m_head;
  Node<T>* current = rhs.m_head;
  Node<T>** tail = &m_head;
  while (current)
  {
    *tail = new Node<T>(current->m_data);
    tail = &tail->m_next;
    current = current->m_next;
  }
}

/*
	Purpose: Linked list 'copy constructor' function; supposed to read through the list -> find a value -> insert before the matching entry 
                 
    Inputs:  input value to search for, and a pointer to insert into the list

    Outputs:  No return values
*/

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList)
{
  Node<T>* current = aList.m_head;
  Node<T>** tail = &m_head;
  while (current)
  {
    *tail = new Node<T>(current->m_data);
    tail = &tail->m_next;
    current = current->m_next;
  }
}

/*
	Purpose: Prepend function; designed to take a linked list node item and place it on the front of the list, shifting the 'head' forward to match 
                 
    Inputs:  Node object to jam onto the front of the list

    Outputs:  No return values
*/

template <class T>
void LinkedList<T>::Prepend(T* input)
{
    if((m_head == NULL) && (m_tail == NULL)) //then the list is empty! this shouldn't really ever happen
    { 
        m_head = m_tail = new Node<T>(input);
        m_tail.m_next = NULL;
    }
    else {
        m_head = new Node<T>(input, m_head);
    }
}

/*
	Purpose: Append function; designed to take a linked list node item and place it at the end of the list, shifting the 'tail' down to match 
                 
    Inputs:  Node object to place at the end of the list

    Outputs:  No return values
*/

template <class T>
void LinkedList<T>::Append(T* input)
{
    if((m_head == NULL) && (m_tail == NULL)) //then the list is empty! 
    { 
        m_head = m_tail = new Node<T>(input);
        m_tail.m_next = NULL;
    }
    else {
        m_tail.m_next = new Node<T>(input); //add new node to end
        m_tail = m_tail.m_next; 
    }
}

/*
	Purpose: Designed to simply pull the input data's value out of the list 
                 
    Inputs:  input value to compare against linked list items

    Outputs:  linked list node object reference matching the input parameter
    
    NOTE: Further review of the lecture notes indicates I should be yanking this value out of the list itself
*/

template <class T>
Node<T>& LinkedList<T>::Extract(T input)
{
    Node<T> *current = m_head;
    Node<T> *temp;
	while(current != NULL)
	{
        if (current->data == input)
        {
            temp = current;
        }
        current = current->m_next;        
	}
    
    return temp;
}

/*
	Purpose: general 'getter' function to return the 'head' portion of the linked list
                 
    Inputs:  no specific inputs

    Outputs:  returns 'm_head' (list header) value
*/

template <class T>
const Node<T>& LinkedList<T>::First() { return m_head; }

/*
	Purpose: general 'getter' function to return the 'tail' portion of the linked list
                 
    Inputs:  no specific inputs

    Outputs:  returns 'm_tail' (list footer) value
*/

template <class T>
const Node<T>& LinkedList<T>::Last()
{
        return m_tail;
}

/*
	Purpose: default constructor for linked list; sets the two values (head and tail) to null values
                 
    Inputs:  no specific inputs

    Outputs:  no returns
*/

template <class T>
LinkedList<T>::LinkedList()
{
        m_tail = NULL;
        m_head = NULL;
}

/*
	Purpose: default destructor for the linked list object class; designed to traverse to clear up the allocated memory 
                 
    Inputs:  no specific inputs

    Outputs:  no outputs
*/

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = m_head;
	while(current != NULL)
	{
		current = current->m_next;
		delete m_head;
		m_head = current;
	}
	m_head = NULL;
	current = NULL;
}

/*
	Purpose: boolean function to determine if the list is empty or not by returning the state of the 'm_head' variable
                 
    Inputs:  no specific inputs

    Outputs:  returns boolean 'not' of m_head (true if m_head is empty, false if it's not)
*/

template <class T>
bool LinkedList<T>::isEmpty()
{
    return !(m_head);
}

/*
	Purpose: function to wipe out the entire linked list (basically enother destructor)
                 
    Inputs:  no specific inputs

    Outputs:  tracks through the linked list, shifting the head forward as it's deleted
*/

template <class T>
void LinkedList<T>::Purge()
{
    Node<T> *current = m_head;
	while(current != NULL)
	{
		current = current->m_next;
		delete m_head;
		m_head = current;
	}
	m_head = NULL;
	current = NULL;
}