#include "mystring.h"

String & String::operator=(const String & s)
{
	delete [] _pstr;
	_pstr = new char[strlen(s._pstr) + 1];
	strcpy(_pstr, s._pstr);
	return *this;
}

String & String::operator=(const char * pc)
{
	String tmp= String(pc);
	*this = tmp;
	return *this;
}

String & String::operator+=(const String & s)
{
	strcat(_pstr, s._pstr);
	return *this;

}
String & String::operator+=(const char * pc)
{
	String tmp= String(pc);
	*this += tmp;
	return *this;
}

char & String::operator[](std::size_t index)
{
	cout <<endl<<"normal char"<<endl;
	if(index >= 0 && index < strlen(_pstr))
		return _pstr[index];
	std::cerr<<"Index out of bounds"<<endl;
	static char nll = '\0';

	cout << " char "<<endl;
	return nll;
}
/*
const char & String::operator[](std::size_t index) const
{
	cout<<endl<< "const char "<<endl;
	return _pstr[index];
}
*/

std::size_t String::size() const
{
	return strlen(_pstr);
}
const char* String::c_str() const
{
	const char * tmp =  _pstr; //!!!think about this!!! with * or not
	return tmp; //return with or without *
}

bool operator==(const String & s1, const String & s2)
{
	return !strcmp(s1._pstr, s2._pstr);

}
bool operator!=(const String & s1, const String & s2)
{
	return !(s1 == s2); 
}

bool operator<(const String & s1, const String & s2)
{
	return (strcmp(s1._pstr, s2._pstr) < 0);
}

bool operator>(const String & s1, const String & s2)
{
	return (strcmp(s1._pstr, s2._pstr) > 0);
}
bool operator<=(const String & s1, const String & s2)
{
	return (s1 < s2) || (s1 == s2);
}
bool operator>=(const String &s1, const String & s2)
{
	return (s1 > s2) || (s1 == s2);
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
	for(size_t i = 0; i< s.size(); ++i)
		os << s._pstr[i];
	return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
	delete []s._pstr;
	char tmp[128];
	is.getline(tmp, 128, '\n'); // 读了多少，放进去后会加'\0'
	s._pstr = new char[strlen(tmp) + 1];
	strcpy(s._pstr , tmp); //所以，这里只会复制到'\0'为止
	cout<<s.size()<<endl;
	return is;
}

String operator+(const String & s1, const String & s2)
{
	char * temp = new char[s1.size() + s2.size() +1];
	strcat(temp, s1.c_str());
	strcat(temp, s2.c_str());
	String rslt(temp);
	delete temp;
	return rslt; 
}


String operator+(const String & s1, const char * s2)
{
	return s1 + String(s2);
}
String operator+(const char * s1, const String & s2)
{
	return String(s1) + s2 ;
}








