#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;


class String {
public:
class cref
{
friend String;
private:
	String &st;
	int index;
	cref(String & s, int i):
		st(s),index(i){}
public:
	operator char(){return st.read(index);}
	void operator =(char c) {st.write(index, c);}
};
private:	
	char * _pstr;
public:
	String():_pstr(new char[5]() + 4){
		init();
		_pstr[0] = '\0';
	} //Initializing with nothing
	String(const char * pch):_pstr(new char[strlen(pch) + 5]() + 4) 
	{
		init();
		strcpy(_pstr, pch);
	}
	String(const String& ps):_pstr(new char[strlen(ps._pstr) + 5]() + 4)
	{
		_pstr = ps._pstr;
		incr();
	}
	~String(){
		rel();
	}
	String &operator=(const String &);
	

	String &operator=(const char *);
	//!!!
	cref operator[](std::size_t index);
	const char read(int index) const {return _pstr[index];}
	char & write(int index, char ch) 
	{	
		if(index >= 0 && index < strlen(_pstr))
		{
			char * tmp = new char[strlen(_pstr) + 5]() + 4;
			strcpy(tmp, _pstr);
			rel();
			_pstr = tmp;
			init();
			_pstr[index] = ch;
		}
		static char none ='\0';
		return none;
	}
	
	
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;
	//!!!	
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);



	int getNum()
	{
		return *(int *)(_pstr - 4);
	}
private:
	void init()
	{
		*(int *)(_pstr - 4) = 1;
	}
	void incr()
	{
		++ *(int *)(_pstr - 4);
	}
	void decr()
	{
		-- *(int *)(_pstr - 4);
	}
	void rel()
	{
		if(getNum() == 1)
			delete [](_pstr - 4);
		else
			decr();
	}
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);


#endif


