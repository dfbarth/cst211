#include <iostream>

using namespace std;

/*
	Purpose: Default Array constructor class
                 
    Inputs:  Instantiation of an Array object without parameters for
	length and start index

    Outputs:  No return values
*/

template <class T>
Array<T>::Array() {
	cout << "Default Constructor with no field data..." << endl;
	m_length = 1;
	m_start_index = 0;
}
/*	
    Purpose: Default Array constructor class
                 
    Inputs:  Instantiation of an Array object with parameters for
	length and start index

    Outputs:  No return values
*/

template <class T>
Array<T>::Array(int length, int start_index) {
	cout << "Default Constructor with field data..." << endl;
	setLength(length);
	m_start_index = start_index;
}

/*
	Purpose: Default Array destructor class
                 
    Inputs:  none

    Outputs:  none
*/

template <class T>
Array<T>::~Array() {
	cout << "Destructor..." << endl;
	//if(m_array != NULL)
	//	delete[] m_array;
}

/*
	Purpose: Set the length of an array; error checking to catch 
	invalid lengths
                 
    Inputs:  Integer value for length of array collection
	length and start index

    Outputs:  No return values
	
	Exceptions: if the length is below a minimum of 1, an invalid
	length exception is thrown
*/

template <class T>
void Array<T>::setLength(int length) { 

	if(length<1)
		throw (Exception((char*) "Invalid Length"));

	int j;
	if (length > m_length)
		j = m_length;
	else
		j = length;	
	T* temp = new T[length];
	int i;
	for(i=0;i<j;i++)
	{
		temp[i] = m_array[i];
	}
	//delete [] m_array;
	m_array = temp;
	temp = NULL;
	m_length = length;
}

/*
	Purpose: to set the starting index (default array index setter)
                 
    Inputs:  integer value for the index

    Outputs:  No return values
*/

template <class T>
void Array<T>::setStartIndex(int start_index) { m_start_index = start_index; }

/*
	Purpose: template getter for array length
                 
    Inputs:  no paramaters passed in

    Outputs:  returns an integer to indicate the number of items in the current collection
*/

template <class T>
int Array<T>::getLength() { return m_length; }

/*
	Purpose: template getter for array 'start index'
                 
    Inputs: no parameters passed in

    Outputs: returns an integer for the array's 'start index'
*/

template <class T>
int Array<T>::getStartIndex() { return m_start_index; }

/*
	Purpose: overloaded assignment operator
                 
    Inputs: an array as input

    Outputs: returns an array of equal length and composition
*/
template <class T>
Array<T> & Array<T>::operator=(const Array<T> & rhs) {
	m_length = rhs.m_length;
	int i;
	for(i=0;i<m_start_index;i++)
		m_array[i] = rhs.m_array[i];
}

/*
	Purpose: overloaded subscript operator
                 
    Inputs: an index for accessing a specific element inside the array space

    Outputs: returns a reference to the template object at index location 'index'
*/
template <class T>
T & Array<T>::operator[](int index) {
	if((index < m_start_index) || (index > m_length))
		throw Exception ((char *) "Index out of bounds");

	return m_array[index];
}
