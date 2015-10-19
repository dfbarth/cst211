/*
    Class: Array2D

    Constructors:	
        Array() 
            m_array, row, and column are all set to 0 by default
        Array2D(int row, int column)
            row and column parameters set the individual member data items
   		~Array();
            cleanup; deallocating the memory as allocated for array pointer objects by traversing the loop, and then turning down the pointer to the top of the array itself

    Mutators:
            
        Row<T> operator[](int index);
            subscript operator for returning indexed items based on input parameters
        Array2D<T> & operator=(const Array2D<T> & rhs);
            assignment operator, to drop one array into another
        void setRow(int rows);
            basic system setter; assigns input value to member data variable 'm_row'
        void setColumn(int column);
            basic system setter; assigns input value to member data variable 'm_col'
            
    Methods:		
        T & Select(int row, int column);
            basic system getter; returns 2d array value based on row and column inputs
        int getRow();
            returns the private member variable m_row
        int getColumn();
            returns the private member variable m_col
            
    Member Data:
        T** m_array;
        int m_row;
        int m_col;

*/

//including the exception class
#include "exception.h"

//predeclaring the row class so that it's accessible to the array2d class
template <class T>
class Row;

template<class T>
class Array2D {
        public:
            Array2D();
            Array2D(int row, int column);
            
            ~Array2D();
            
       		Row<T> operator[](int index);
            T & Select(int row, int column);
            Array2D<T> & operator=(const Array2D<T> & rhs);

            int getRow();
            int getColumn();
            
            void setRow(int rows);
            void setColumn(int column);
            
        private:
            T** m_array;    //2d template array object
            int m_row;      //row index
            int m_col;      //column index
};

#include "array2D.cpp"

