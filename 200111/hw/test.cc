 ///
 /// @file    test.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-09 21:19:57
 ///

#include "mystring.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main(void)
{
	String s1("Hi");	
	String s2("Hello");
	String s3 = s2;
	//const String s4("const hello");
	
//	s3 = "hi";


	cout<< "s1: " << s1 << "\t" << s1.getNum() << endl
		<< "s2: " << s2 << "\t" << s2.getNum() << endl
		<< "s3: " << s3 << "\t" << s3.getNum() << endl;
	
	cout<<endl;


	cout<< "s1[1]: " << s1[1] << "\t" << s1.getNum() << endl
		<< "s2[1]: " << s2[1] << "\t" << s2.getNum() << endl
		<< "s3[1]: " << s3[1] << "\t" << s3.getNum() << endl;
	//	<< "s3: " << s4 << "\t" << s4.getNum() << endl;

	cout << endl;


	char temp = 'g';
//	cout << "char = ";
//	cin >>temp;
	s1[1] = temp;
	s2[1] = temp;

	cout<<"after changing s1 s2" << endl;
	cout<< "s1: " << s1 << "\t" << s1.getNum() << endl
		<< "s2: " << s2 << "\t" << s2.getNum() << endl
		<< "s3: " << s3 << "\t" << s3.getNum() << endl;
	cout<< "s1[1]: " << s1[1] << "\t" << s1.getNum() << endl
		<< "s2[1]: " << s2[1] << "\t" << s2.getNum() << endl
		<< "s3[1]: " << s3[1] << "\t" << s3.getNum() << endl;


	
	return 0;
}
