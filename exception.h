/********************************************************************
 * Author:					David Bartholomew
 * Date Created:			09/28/2015
 * Last Modification Date:	10/03/2015
 * Filenames:				exception.h
 *
 * Overview:
 * 	Exception header file for assignment 1
 * Algorithm:
 * 	Default constructor, constructor with parameters, default destructor
 * 	and copy constructor
 * 	built out overloaded operators for ease and transparency of use
 * 	built out getters and setters; 
 *
 **********************************************************************/


#include <iostream>

using namespace std;

class Exception {
	public:
		Exception();
		Exception(char * msg);
		Exception(const Exception& aException);
		~Exception();

		Exception & operator=(Exception & aException);
		friend ostream & operator<<(ostream&, Exception & aException);	
		char* getMessage() const;
		void setMessage(char * message);
	private:
		char * m_msg;	
};

Exception::Exception() {
	cout << "Exception constructor witout params..." << endl;
	//m_msg = "Non-specific error...";
}


Exception::Exception(char * msg) {
	cout << "Exception constructor with message..." << endl;
	setMessage(msg);
}

Exception::Exception(const Exception& aException) {
	cout << "Copy Constructor..." << endl;
	setMessage(aException.getMessage());
}

Exception::~Exception() {
	cout << "Exception Destructor..." << endl;
	if(m_msg != NULL)
		delete[] m_msg;
}

Exception & Exception::operator=(Exception & aException) {
	int b=strlen(aException.getMessage())+1;
	memcpy(m_msg,aException.getMessage(),b);
}

ostream& operator<<(ostream&, Exception & aException) {
	cout << aException.getMessage() << endl;
}

void Exception::setMessage(char * message) {
	if(m_msg != NULL)
	{
		delete [] m_msg;
		
	}
	int b=strlen(message)+1;
	m_msg = new char[b];
	memcpy(m_msg,message,b);
}

char * Exception::getMessage() const { return m_msg; }

