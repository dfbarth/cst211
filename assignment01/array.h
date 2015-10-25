#include <iostream>

using namespace std;

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

#include "array.cpp"
