#ifndef MYSTACK_H
#define MYSTACK_H

#define  MAX 50

class MyStack
{
// The variable, pos, points at the top element.
private:
	int a[MAX];
	int pos;
public:
	MyStack():pos(-1){}
	void push(int);
	void pop();
	int top();
	bool empty();
	bool full();
};
 
#endif
