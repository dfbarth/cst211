#include <iostream>
#include "array.h"

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
	cout << "Please enter an index to evaluate: ";

	return 0;

}
