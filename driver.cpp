/*

    Author:			David Bartholomew
    Date Created:		10/09/15
    Class information:		CST 211; Joshua Dutton
    Filename:			driver.cpp

    Overview: testing file for assignment 1; designed to 
    demonstrate instantiation of a templated array and 
    to test the assigned exception class

    Input: no inputs
    
    Output: outputs to the console
   
*/

#include <iostream>
#include "array.h"
#include "exception.h"

using namespace std;

const int MAX_BUF = 40; 	

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
