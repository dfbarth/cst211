#include <iostream>

/*	Purpose: Default Exception constructor class
                 
    Inputs:  Instantiation of an Exception object with no parameters

    Outputs:  No return values
*/
Exception::Exception() {
	char msg[] = "Non-specific error...";
	setMessage(msg);
}

/*	Purpose: Default Exception constructor class
                 
    Inputs:  Instantiation of an Exception object with the parameter
	for the exception message

    Outputs:  No return values
*/
Exception::Exception(char * msg) {
	setMessage(msg);
}

/*	Purpose: copy constructor; designed to copy one exception to another via reference
                 
    Inputs: takes an existing exception by reference, applies the input exception's message to the target exception

    Outputs: no return values
*/
Exception::Exception(const Exception& aException) {
	setMessage(aException.getMessage());
}

/*	Purpose: default destructor; if memory is allocated for exception objects, this deallocates it as the object goes out of scope
                 
    Inputs:  no inputs

    Outputs:  no outputs
*/
Exception::~Exception() {
	if(m_msg != NULL)
		delete[] m_msg;
}

/*	Purpose: overloaded assignment operator; designed to take an exception by reference, and assigning the message to the target
                 
    Inputs: an exception by reference

    Outputs:  an exception object with a matching message data member
*/
Exception & Exception::operator=(Exception & aException) {
	int b=strlen(aException.getMessage())+1;
	memcpy(m_msg,aException.getMessage(),b);
}

/*	Purpose: overloaded bitwise operator; so that exception messages can be passed out as required, regardless of the available output structure
                 
    Inputs: an exception passed by reference

    Outputs: the exception object message, passed to whatever output stream is available and specified
*/
std::ostream& operator<<(std::ostream& stream, Exception & aException) {
	stream << aException.getMessage();
	return stream;
}

/*	Purpose: an exception setter; takes a string and sets the object's member data
                 
    Inputs: a char array containing the message for a thrown exception

    Outputs: no outputs 
*/
void Exception::setMessage(char * message) {
	if(m_msg != NULL)
	{
		delete [] m_msg;
		
	}
	if(m_msg == NULL)
	{
		int b=strlen(message)+1;
		m_msg = new char[b];
		memcpy(m_msg,message,b);
	}
}

/*	Purpose: an exception getter; pulls the private member data out of the object
                 
    Inputs: no inputs

    Outputs: returns a char array containing the exception object's message
*/
char * Exception::getMessage() const { return m_msg; }
