/*
	Purpose: row constructor; preassigns m_array2d and m_row member values
                 
    Inputs:  array2d (by reference) and row parameters
    
    Outputs:  No return values
*/

template<class T>
Row<T>::Row(Array2D<T> & array, int row):
        m_array2D (array),
        m_row (row)
        {
            
        }

/*
	Purpose: destructor 
                 
    Inputs:  at this time, no memory is being directly allocated for row objects

    Outputs:  No return values
*/

template <class T>
Row<T>::~Row() {
    //no memory cleanup required at this time
    //since we're dealing with references, not pointers

}

/*
	Purpose: overloaded subscript operator; designed to simply pass entire rows back into the main array2d function
                 
    Inputs:  integer column value

    Outputs:  returns the value currently stored at the array2d value for [row][column]
*/

template <class T>
T & Row<T>::operator[](int column) {

    if((column<0) || (column>(m_array2D.getRow())-1))
    {
		throw (Exception((char*) "Out of bounds column error"));
    }

    return m_array2D.Select(m_row,column);

}

