/********************************************************************
 * Author:					David Bartholomew
 * Date Created:			09/28/2015
 * Last Modification Date:	10/03/2015
 * Filenames:				driver.cpp
 *
 * Overview:
 * 	basic 'testing' file for assignment 1
 * Algorithm:
 * 	Instantiation of array objects, testing the dynamic nature of the
 * 	arrays, and testing the exception conditions per the assignment 
 * 	guidelines
 *
 *********************************************************************/

#include <iostream>
#include "array.h"
#include "exception.h"

using namespace std;

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
		cout << "Array value at index 45 is: ";
	try {	
		intArray[45];
	}
	catch (const Exception &error_msg) {
		cout << "Exception: " << error_msg.getMessage() << endl;	
	}

	return 0;

}

