 ///
 /// @file    test1.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-05 19:10:24
 ///
 
#include <iostream>
#include "mystack.h"

using std::cout;
using std::endl;
 
int main(void)
{
	try 
	{
		MyStack ms;
		//ms.pop();
		ms.push(10);
		ms.push(12);
		ms.push(14);
		cout<<"Top is "<<ms.top()<<endl;
		ms.pop();
		cout<<"Top is "<<ms.top()<<endl;
	}
	catch(int e)
	{
		if(e == 1) cout<<"EXCEPTION: Stack is FULL!"<<endl;
		if(e == 2) cout<<"EXCEPTION: Stack is EMPTY!"<<endl;
	}

	return 0;
}
