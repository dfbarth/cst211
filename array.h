#include <iostream>

using namespace std;

const int MAX_BUF = 40; 	//we aren't given a top bound, so 
				//I'm arbitrarily choosing one

template<class T>
class Array{
	public:
		Array();
		Array(int length, int start_index);
		~Array();

		T & 	operator[](int index);
		Array<T> & operator=(const Array<T> & rhs);
	
		void setLength(int length);
		void setStartIndex(int start_index);

		int getLength();
		int getStartIndex();

	private:
		T* m_array;
		int m_length;
		int m_start_index;		
};

template <class T>
Array<T>::Array() {
	cout << "Default Constructor with no field data..." << endl;
	m_length = 1;
	m_start_index = 0;
}

template <class T>
Array<T>::Array(int length, int start_index) {
	cout << "Default Constructor with field data..." << endl;
	m_length = length;
	m_start_index = start_index;
}

template <class T>
Array<T>::~Array() {
	cout << "Destructor..." << endl;
	//if(m_array != NULL)
	//	delete[] m_array;
}

template <class T>
void Array<T>::setLength(int length) { 
	int j;
	if (length > m_length)
		j = m_length;
	else
		j = length;	
	T* temp = new T[length];
	int i;
	for(i=0;i<j;i++)
	{
		temp[i] = m_array[i];
	}
	//delete [] m_array;
	m_array = temp;
	temp = NULL;
	m_length = length;
}

template <class T>
void Array<T>::setStartIndex(int start_index) { m_start_index = start_index; }

template <class T>
int Array<T>::getLength() { return m_length; }
template <class T>
int Array<T>::getStartIndex() { return m_start_index; }

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & rhs) {
	m_length = rhs.m_length;
	int i;
	for(i=0;i<m_start_index;i++)
		m_array[i] = rhs.m_array[i];
}

template <class T>
T & Array<T>::operator[](int index) {
	return m_array[index];
}

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
	m_msg = "Non-specific error...";
}


Exception::Exception(char * msg) {
	cout << "Exception constructor with message..." << endl;
	int b=strlen(msg)+1;
	memcpy(m_msg,msg,b);
}

Exception::Exception(const Exception& aException) {
	cout << "Copy Constructor..." << endl;
	m_msg = new char[MAX_BUF];
	int b=strlen(aException.getMessage())+1;
	memcpy(m_msg,aException.getMessage(),b);
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
	int b=strlen(message)+1;
	memcpy(m_msg,message,b);
}

char * Exception::getMessage() const { return m_msg; }