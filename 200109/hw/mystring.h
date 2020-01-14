#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;


class String {
public:
	String():_pstr(new char[1]){} //Initializing with nothing
	String(const char * pch):_pstr(new char[strlen(pch) + 1])
	{
		strcpy(_pstr, pch);
	}
	String(const String& ps):_pstr(new char[strlen(ps._pstr) + 1])
	{
		strcpy(_pstr, ps._pstr);
	}
	~String(){ delete []_pstr;}
	String &operator=(const String &);
	String &operator=(const char *);

	String &operator+=(const String &);
	String &operator+=(const char *);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;//can this be distinguished?

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);







#endif


