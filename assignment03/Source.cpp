/*

Author:				    David Bartholomew
Date Created:			10/24/15
Class information:		CST 211; Joshua Kimball
Filename:				Source.cpp

Overview: testing file for assignment 3; designed to demonstrate a working iterator and linked list system.
	complete rebuild from the first version of this assignment I submitted. A lot of review and examination
	went into working out a better model for myself on how pointers worked, how they were accessed and modified

Input: no inputs

Output: outputs to the console

*/


#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

	LinkedList<int> labLinkedList1(new Node<int>(5));         //testing a list with initialization data 
	//labLinkedList1.printList();                               //testing getting data out of the node

	LinkedList<int> labLinkedList2(new Node<int>());            //testing an empty list
	cout << "Empty: " << labLinkedList2.isEmpty() << endl;
	cout << "Prepending!" << endl;
	int a = 15;
	int * b = &a;
	labLinkedList2.Prepend(&a); //I could do it this way
	a = 20;
	labLinkedList2.Prepend(b);  //or this way
	//labLinkedList2.printList();								//by this point, my lungs were *aching* for air
	a = 44;
	labLinkedList2.Prepend(b);
	cout << "Appending!" << endl;
	a = 23;
	labLinkedList2.Append(b);
	a = 88;
	labLinkedList2.Append(b);
	a = 45;
	labLinkedList2.Append(b);
	//labLinkedList2.printList();
	//Iterator<int> index(labLinkedList2.Begin());
	Iterator<int> index;									//let the iterator testing begin
	index = labLinkedList2.Begin();
	for (; index.getNode() != NULL; index++)
	{
		cout << "++ Entry for LL1: ";
		cout << index.getNode()->getData();
		cout << endl;
	}
	cout << "Index check!" << endl;							//since index is now at the end of the list, let's go back
	index = labLinkedList2.End();
	for (; index.getNode() != NULL; index--)
	{
		cout << "-- Entry for LL1: ";
		cout << index.getNode()->getData();
		cout << endl;
	}
	cout << "Extracting!" << endl;
	Node<int> tempNode;
	tempNode = labLinkedList2.Extract(88);
	cout << "Extracted! ";
	cout << tempNode.getData();
	cout << endl;
	index = labLinkedList2.Begin();
	for (; index.getNode() != NULL; index++)
	{
		cout << "++ Entry for LL2: ";
		cout << index.getNode()->getData();
		cout << endl;
	}

	LinkedList<int> labLinkedList3(new Node<int>());          //testing the deep copy
	labLinkedList3 = labLinkedList2;

	cout << "Purging!" << endl;
	labLinkedList2.Purge();
	
	cout << "Empty: " << labLinkedList2.isEmpty() << endl;

	index = labLinkedList3.Begin();
	for (; index.getNode() != NULL; index++)
	{
		cout << "++ Entry for LL3: ";
		cout << index.getNode()->getData();
		cout << endl;
	}

	cout << "Purging!" << endl;
	labLinkedList3.Purge();

	cout << "Empty: " << labLinkedList3.isEmpty() << endl;

	return 0;

}