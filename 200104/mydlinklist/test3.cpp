 ///
 /// @file    test3.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-05 22:34:39
 ///
 
#include <iostream>
#include "dllist.h"
using std::cout;
using std::endl;
 
int main(void)
{
	cout<<0<<endl;
	List ml;
	cout<<0<<endl;

	ml.push_back(1);
	cout<<0<<endl;
	ml.push_back(2);
	ml.push_front(3);
	cout<<0<<endl;
	ml.display();
	cout<<0<<endl;

	ml.pop_back();
	ml.display();
	ml.pop_front();
	ml.display();
	ml.pop_back();
	ml.display();


	ml.push_back(1);
	ml.push_back(2);
	ml.push_back(3);
	ml.push_back(4);
	ml.push_back(5);
	ml.push_back(6);
	ml.display();
	if (ml.find(3)) cout<<"We have 3"<<endl;
	if (!ml.find(9)) cout<<"We don't have 9"<<endl;
	ml.erase(3);
	ml.display();
	ml.insert(ml.find(4),3);
	ml.display();


	return 0;
}
