 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 22:18:24
 ///
 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <sstream>
using std::stringstream;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
	stringstream ss;
	ss<< ("%s %d %s", __FILE__, __LINE__, __FUNCTION__);
		
	string s(ss.str());


	cout<< s<< endl;

	//printf("%s %d %s", __FILE__, __LINE__, __FUNCTION__);

	return 0;
}
