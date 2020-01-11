#include "mystack.h"

//const int MAX = 50;

void MyStack::push(int val)
{
	if(full()) throw 1;// FULL EXCEPTION
	pos++;
	a[pos] = val;
}
void MyStack:: pop()
{
	if(empty()) throw 2; //EMPTY EXCEPTION
	pos--;
}
int MyStack:: top()
{
	
	if(empty()) throw 2; //EMPTY EXCEPTION
	return a[pos];
}
bool MyStack::empty()
{
	return pos == -1;
}
bool MyStack::full()
{
	return pos == MAX - 1;
}


 
