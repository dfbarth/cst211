/*
    Class: Row

    Constructors:	
        Row(Array2D<T> & array, int row) 
            constructor that requires an array parameter and a row value - builds a row collection of the templated Array2D object
   		~Row();
            basic memory cleanup; no memory directly allocated at this time
            
    Mutators:
        none    
            
    Methods:		
		T & operator[](int column)
            overloaded subscript operator to return 'rows' of templated T objects
            
    Member Data:
        Array2D<T> & m_array2D;
        int m_row;

*/
#include <iostream>

template<class T>
class Array2D;

template <class T>
class Row {
        public:
            Row(Array2D<T> & array, int row);
            ~Row();
            T & operator[](int column);
        
        private:
            Array2D<T> & m_array2D;
            int m_row;
};

#include "row.cpp"

