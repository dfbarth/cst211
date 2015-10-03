/********************************************************************
 * Author:					David Bartholomew
 * Date Created:			09/28/2015
 * Last Modification Date:	10/03/2015
 * Filenames:				array.h
 *
 * Overview:
 * 	Array header file for assignment 1
 * Algorithm:
 * 	Default constructor, constructor with parameters, default destructor
 * 	built out overloaded operators for ease and transparency of use
 * 	built out getters and setters; used assigned constraints as a means
 * 	to implement exception handling internally
 *
 **********************************************************************/

#include <iostream>
using namespace std;

const int MAX_BUF = 40; 	
				
class Exception;

template<class T>
class Array{
	public:
		Array();
		Array(int length, int start_index);
		~Array();

		T & 	operator[](int index);
		Array<T> & operator=(const Array<T> & rhs);
	
		void setLength(int length);
		void setStartIndex(int start_index);

		int getLength();
		int getStartIndex();

	private:
		T* m_array;
		int m_length;
		int m_start_index;		
};

template <class T>
Array<T>::Array() {
	cout << "Default Constructor with no field data..." << endl;
	m_length = 1;
	m_start_index = 0;
}

template <class T>
Array<T>::Array(int length, int start_index) {
	cout << "Default Constructor with field data..." << endl;
	setLength(length);
	m_start_index = start_index;
}

template <class T>
Array<T>::~Array() {
	cout << "Destructor..." << endl;
	//if(m_array != NULL)
	//	delete[] m_array;
}

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
	m_array = temp;
	temp = NULL;
	m_length = length;
}

template <class T>
void Array<T>::setStartIndex(int start_index) { m_start_index = start_index; }

template <class T>
int Array<T>::getLength() { return m_length; }
template <class T>
int Array<T>::getStartIndex() { return m_start_index; }

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & rhs) {
	m_length = rhs.m_length;
	int i;
	for(i=0;i<m_start_index;i++)
		m_array[i] = rhs.m_array[i];
}

template <class T>
T & Array<T>::operator[](int index) {
	if((index < m_start_index) || (index > m_length))
		throw Exception ((char *) "Index out of bounds");

	return m_array[index];
}

