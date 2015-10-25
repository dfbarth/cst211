/*

    Author:				    David Bartholomew
    Date Created:			10/09/15
    Class information:		CST 211; Joshua Kimball
    Filename:				driver.cpp

    Overview: testing file for assignment 2; designed to 
    demonstrate instantiation of a templated 2d array based on
    provided UML documentation

    Input: no inputs
    
    Output: outputs to the console
      
*/

#include <iostream>
#include "exception.h"
#include "row.h"
#include "array2D.h"

using namespace std;

int main()
{
    Array2D<int> foo(10,10);
    foo[0][0] = 42;
    cout << "data value out, not using select: " << foo[0][0] << endl;
    cout << "data value out, using select: " << foo.Select(0,0) << endl;
    Array2D<int> bar(10,10);
    bar = foo;
    cout << "trying the assignment operator: " << bar.Select(0,0) << endl;
    cout << "now for some errors:" << endl;
    cout << "out of bounds row: ";
    try { 
        foo[11][0]; 
    }
    catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;
	}   cout << endl;
    cout << "out of bounds column: ";
    try { 
        bar[0][20]; 
    }
    catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;
	}   cout << endl;
    cout << "out of bounds using select: ";
    try { 
        foo.Select(41,2);
    }
    catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;
	}   cout << endl;
    
	return 0;

}
