/*

    Author:				    David Bartholomew
    Date Created:			10/09/15
    Class information:		CST 211; Joshua Dutton
    Filename:				driver.cpp

    Overview: testing file for assignment 1; designed to 
    demonstrate instantiation of a templated array and 
    to test the assigned exception class

    Input: no inputs
    
    Output: outputs to the console
   
*/

#include <iostream>

using namespace std;

const int MAX_BUF = 40; 	

class Exception;

/*
    Class: Array

    Constructors:	
        Array() 
            length is set to 1, the index to 0 by default
        Array(int length, int start_index);
            parameters set the individual member data items
   		~Array();
            cleanup; deallocating the memory as allocated for array pointer objects

    Mutators:
            
		Array<T> & operator=(const Array<T> & rhs);
            assignment operator that allows one member of a collection to be assigned to an instance of another
        void setLength(int length)
            sets a collection's number of elements
        void setStartIndex(int start_index)
            sets the member data value

    Methods:		
		int getLength();
            returns an integer value to indicate the number of elements in the current collection
		int getStartIndex();
            returns whatever value is held in the member data variable 
   		T & operator[](int index);
            subscript operator for returning indexed items based on input parameters

    Member Data:
		T* m_array;
		int m_length;
		int m_start_index;		

*/

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

/*
    Class: Exception

    Constructors:	
		Exception();
            default constructor - sets the message to a 'non-specific' exception message
		Exception(char * msg);
            constructor with parameters - sets the message to the input
		Exception(const Exception& aException);
            copy constructor; sets one exception to another by reference
		~Exception();
            default destructor; if any memory is allocated for exception objects, it is cleaned up here

    Mutators:
		void setMessage(char * message);
            sets member data value msg to the input value
		Exception & operator=(Exception & aException);
            overloaded assignment operator, allowing one exception to be assigned to an instance of another

    Methods:		
		char* getMessage() const;
            returns the member value message
		friend ostream & operator<<(ostream&, Exception & aException);	
            overloaded bitwise operator allowing exceptions to output data to any kind of stream
    
    
*/

class Exception {
	public:
		Exception();
		Exception(char * msg);
		Exception(const Exception& aException);
		~Exception();

		Exception & operator=(Exception & aException);
		friend ostream & operator<<(ostream&, Exception & aException);	
		char* getMessage() const;
		void setMessage(char * message);
	private:
		char * m_msg;	
};

/*	Purpose: Default Exception constructor class
                 
    Inputs:  Instantiation of an Exception object with no parameters

    Outputs:  No return values
*/
Exception::Exception() {
	cout << "Exception constructor witout params..." << endl;
	char msg[] = "Non-specific error...";
	setMessage(msg);
}

/*	Purpose: Default Exception constructor class
                 
    Inputs:  Instantiation of an Exception object with the parameter
	for the exception message

    Outputs:  No return values
*/
Exception::Exception(char * msg) {
	cout << "Exception constructor with message..." << endl;
	setMessage(msg);
}

/*	Purpose: copy constructor; designed to copy one exception to another via reference
                 
    Inputs: takes an existing exception by reference, applies the input exception's message to the target exception

    Outputs: no return values
*/
Exception::Exception(const Exception& aException) {
	cout << "Copy Constructor..." << endl;
	setMessage(aException.getMessage());
	//m_msg = new char[MAX_BUF];
	//int b=strlen(aException.getMessage())+1;
	//memcpy(m_msg,aException.getMessage(),b);
}

/*	Purpose: default destructor; if memory is allocated for exception objects, this deallocates it as the object goes out of scope
                 
    Inputs:  no inputs

    Outputs:  no outputs
*/
Exception::~Exception() {
	cout << "Exception Destructor..." << endl;
	if(m_msg != NULL)
		delete[] m_msg;
}

/*	Purpose: overloaded assignment operator; designed to take an exception by reference, and assigning the message to the target
                 
    Inputs: an exception by reference

    Outputs:  an exception object with a matching message data member
*/
Exception & Exception::operator=(Exception & aException) {
	int b=strlen(aException.getMessage())+1;
	memcpy(m_msg,aException.getMessage(),b);
}

/*	Purpose: overloaded bitwise operator; so that exception messages can be passed out as required, regardless of the available output structure
                 
    Inputs: an exception passed by reference

    Outputs: the exception object message, passed to whatever output stream is available and specified
*/
ostream& operator<<(ostream& stream, Exception & aException) {
	stream << aException.getMessage();
	return stream;
}

/*	Purpose: an exception setter; takes a string and sets the object's member data
                 
    Inputs: a char array containing the message for a thrown exception

    Outputs: no outputs 
*/
void Exception::setMessage(char * message) {
	if(m_msg != NULL)
	{
		delete [] m_msg;
		
	}
	if(m_msg == NULL)
	{
		int b=strlen(message)+1;
		m_msg = new char[b];
		memcpy(m_msg,message,b);
	}
}

/*	Purpose: an exception getter; pulls the private member data out of the object
                 
    Inputs: no inputs

    Outputs: returns a char array containing the exception object's message
*/
char * Exception::getMessage() const { return m_msg; }

int main()
{
	Array<int> intArray(6,0);
	intArray[1] = 2;	
	cout << "Array value at index 1 is: " << intArray[1] << endl;
	cout << "Changing the length from 6 to 8" << endl;
	intArray.setLength(8);
	intArray[6] = 5;
	cout << "Array value at index 7 is: " << intArray[6] << endl;
	int i;
	for(i=0;i<intArray.getLength();i++)
	{
		intArray[i] = i*i;
	}
		cout << "Checking 'invalid length condition'." << endl;
	try {	
		Array<int> badArray(-1,0);
	}
	catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;
	}	
		cout << "Checking 'out of bounds' index." << endl;
	try {	
		cout << "Array value at index 45 is: " << intArray[45] << endl;
	}
	catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;	
	}

	return 0;

}
