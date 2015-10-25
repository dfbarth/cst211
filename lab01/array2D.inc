/*
	Purpose: Default array2d constructor class
                 
    Inputs:  Instantiation of an array2d object without parameters for m_array, m_row, and m_col values; all are set to 0 by default

    Outputs:  No return values
*/

template <class T>
Array2D<T>::Array2D() {
    m_array = 0;
    m_row = 0;
    m_col = 0;
}

/*
	Purpose: Default array2d constructor class 
                 
    Inputs:  Instantiation of an array2d object with parameters for m_row, and m_col values; both are set based upon input values

    Outputs:  No return values
*/

template <class T>
Array2D<T>::Array2D(int row, int column) {
    m_array = new T* [row];
    int i;
    for(i=0;i<row;i++)
        m_array[i] = new T[column];
    m_row = row;
    m_col = column;
    
}

/*
	Purpose: array2d overloaded assignment operator
                 
    Inputs:  allows setting of an array2d object from a source array2d object

    Outputs:  returns a second array2d object with values that match the source object
*/

template <class T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> & rhs) {
	int i,j;
	for(i=0;i<m_row;i++)
    {
        for(j=0;j<m_col;j++)
        {
            m_array[i][j] = rhs.m_array[i][j];
        }
    }
}

/*
	Purpose: Default array2d deconstructor class; loops through the entire 2d array to deallocate memory first at the internal column level, and then at the top row level
                 
    Inputs:  no inputs

    Outputs:  no outputs
*/

template <class T>
Array2D<T>::~Array2D() {
    if(m_array != NULL)
    {
        int i;
        for(i=0;i<m_row;i++)
        {
            delete[] m_array[i];
        }
        delete[] m_array;
    }
}

/*
	Purpose: array2d overloaded subscript operator; grants access to row elements based on index
                 
    Inputs:  index to determine which row out of the 2d array to return

    Outputs:  returns an entire row
    
    Exceptions: if an index that's less than zero or greater than the top end of the 2d array is submitted, an 'out of bounds' exception is thrown
*/

template <class T>
Row<T> Array2D<T>::operator[](int row) {
    Row<T> f_row(*this,row);

    if((row<0) || (row>m_row-1))
    {
       	throw (Exception((char*) "Out of bounds row error"));
    }
    
    return f_row;
}

/*
	Purpose: array2d item getter, based on two subscripts - one for row, one for column
                 
    Inputs:  ints to indicate row and column

    Outputs:  returns the specific element found at [row][column]
*/

template <class T>
T& Array2D<T>::Select(int row, int column) {
    if((row<0) || (column<0) || (row>m_row) || (column>m_col))
    {
            throw (Exception((char*) "Out of bounds select error"));
    }
    
    return m_array[row][column];
}

/*
	Purpose: basic array2d getter
                 
    Inputs:  no inputs

    Outputs:  returns the current value of private member data item 'm_row'
*/

template <class T>
int Array2D<T>::getRow() { return m_row; }

/*
	Purpose: basic array2d getter
                 
    Inputs:  no inputs

    Outputs:  returns the current value of private member data item 'm_col'
*/

template <class T>
int Array2D<T>::getColumn() { return m_col; }

/*
	Purpose: basic array2d setter
                 
    Inputs:  takes an int as a parameter

    Outputs:  sets the current value of private member data item 'm_row' to the input value
*/

template <class T>
void Array2D<T>::setRow(int row) { m_row = row; }

/*
	Purpose: basic array2d setter
                 
    Inputs:  takes an int as a parameter

    Outputs:  sets the current value of private member data item 'm_col' to the input value
*/

template <class T>
void Array2D<T>::setColumn(int column) { m_col = column; }

