#ifndef MYQUEUE_H
#define MYQUEUE_H

#define MAX 50

class MyQueue
{
// The tail points at the next position of the last element.
private:
	int q[MAX];
	int head;
	int tail;

public:
	MyQueue():head(0),tail(0){}
	void push(int);
	void pop();
	int front();
	int back();
	bool empty();
	bool full();

};



#endif
