 ///
 /// @file    test2.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-05 19:56:02
 ///
 
#include <iostream>
#include "myqueue.h"
using std::cout;
using std::endl;
 
int main(void)
{
	try
	{
		MyQueue mq;
//		mq.pop();
		if (mq.empty()) cout<<"The queue is empty."<<endl;
		mq.push(2);
		mq.push(6);
		mq.push(9);
		cout<<" The front is "<<mq.front()<<endl
			<<" The back is " <<mq.back()<<endl;
		if (!mq.full()) cout<<" The queue is not full."<<endl;
	}
	catch(int e )
	{
		if (e == 1) cout<<"EMPTY EXCEPTION!"<<endl;
		if (e == 2) cout<<"FULL EXCEPTION!"<<endl;
	}
}
