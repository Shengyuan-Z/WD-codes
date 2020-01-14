#include "mystring.h"
String & String::operator=(const String & s)
{
	if(this != &s) 
	{
		rel();
		_pstr = s._pstr;//inside the String, use _pstr directly
		incr();
	}
	return *this;
}

String & String::operator=(const char * pc)
{
	rel();
	_pstr = new char[strlen(pc) + 5]() + 4;
	strcpy(_pstr, pc);
	init();
	return *this;
}



//!!!
String::cref  String::operator[](std::size_t index)
{
	if(index >= 0 && index < strlen(_pstr))
		return cref(*this, index);
	
	std::cerr<<"Index out of bounds"<<endl;
	static String None;
	static cref nothing(None, 0);
	return nothing;
}

const char & String::operator[](std::size_t index) const
{
	cout<<endl<< "const char "<<endl;
	return _pstr[index];
}

std::size_t String::size() const
{
	return strlen(_pstr);
}
const char* String::c_str() const
{
	return _pstr;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
	for(size_t i = 0; i< s.size(); ++i)
		os << s._pstr[i];
	return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
	s.rel();
	char tmp[128];
	is.getline(tmp, 128, '\n'); // 读了多少，放进去后会加'\0'
	s._pstr = new char[strlen(tmp) + 5]() + 4;
	s.init();
	strcpy(s._pstr , tmp); //所以，这里只会复制到'\0'为止
	//cout<<s.size()<<endl;
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








