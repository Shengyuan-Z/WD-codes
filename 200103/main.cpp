#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String * rhs);
	String & operator=(const String * rhs);
	~String();

	void print();

private:
	char * _pstr;
};

String::String():_pstr(NULL){cout<<"()"<<endl;}
String::String(const char *pstr)
	:_pstr(new char[strlen(pstr+1)]())
{
	strcpy(_pstr,pstr);
	cout<<"cc"<<endl;
}
String::String(const String * rhs)
:_pstr(new char[strlen(rhs->_pstr)+1]())
{	
	strcpy(_pstr,rhs->_pstr);
	cout<<"cs"<<endl;
}

String & String:: operator=(const String * rhs)
{
	if( this ==  rhs) return *this;//比较的是rhs的地址！！返回的是实例！！
	//mod
	delete[] _pstr;
	_pstr = new char[strlen(rhs->_pstr)+1];	
	strcpy(_pstr,rhs->_pstr);
	cout<<"="<<endl;
	return * this;
}
String::~String()
{
	//mod! delete [] _pstr;
	if(!_pstr)
	{	
		delete [] _pstr;
//		_pstr = nullptr; //避免野指针
	}
}

void String::print()
{
	if( _pstr != NULL)
	{
		cout<<"print:";
		for(int i = 0; i < strlen(_pstr); i++) cout<<_pstr[i];
		cout<<endl;
	}
}


int main(void)
{
	String str1;
	str1.print();
	
	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	
	return 0;
}
