#include <iostream>
#include <cstring>

/*
    Class: Exception

    Constructors:	
		Exception();
            default constructor - sets the message to a 'non-specific' exception message
		Exception(char * msg);
            constructor with parameters - sets the message to the input
		Exception(const Exception& aException);
            copy constructor; sets one exception to another by reference
		~Exception();
            default destructor; if any memory is allocated for exception objects, it is cleaned up here

    Mutators:
		void setMessage(char * message);
            sets member data value msg to the input value
		Exception & operator=(Exception & aException);
            overloaded assignment operator, allowing one exception to be assigned to an instance of another

    Methods:		
		char* getMessage() const;
            returns the member value message
		friend std::ostream & operator<<(std::ostream& stream, Exception & aException);	
            overloaded bitwise operator allowing exceptions to output data to any kind of stream
    
*/

class Exception {
	public:
		Exception();
		Exception(char * msg);
		Exception(const Exception& aException);
		~Exception();

		Exception & operator=(Exception & aException);
		friend std::ostream & operator<<(std::ostream& stream, Exception & aException);	
		char* getMessage() const;
		void setMessage(char * message);
	private:
		char * m_msg;	
};

#include "exception.tcc"
