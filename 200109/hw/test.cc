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
	String s1;
	cin>>s1;	
	String s2("Hello");
	String s3 = s2;
	const String s4("const hello");

	cout<< "s1: " << s1 << endl
		<< "s2: " << s2 << endl
		<< "s3: " << s3 << endl
		<< "s3: " << s4 << endl;

	cout << endl;
/*
	cout <<" s1 == s2 ? "<< (s1 == s2? 'T':'F')<< endl
		 <<" s2 == s3 ? "<< (s2 == s3? 'T':'F')<< endl
		 <<" s1 >  s2 ?" << (s1 >  s2? 'T':'F')<< endl
		 <<" s2 >= s3 ?" << (s2 >= s3? 'T':'F')<< endl;
*/		 
	
	cout<<"char s1[0]: " << s1[0] << endl;
	cout<<"const char s4[0]: " << s4[0] <<endl;
//	cout<<s1 + s2 << endl;
//	cout<<s1 + "hi"<<endl;
	return 0;
}
