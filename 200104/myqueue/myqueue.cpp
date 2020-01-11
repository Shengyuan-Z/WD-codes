#include "myqueue.h"


void MyQueue::push(int val)
{
	if(full()) throw 2; // EXCEPTION FULL
	q[tail] = val ; 
	tail++;
}

void MyQueue::pop()
{
	if (empty()) throw 1; // EXCEPITION EMPTY
	tail--;
}

int MyQueue::front()
{
	if (empty()) throw 1; // EXCEPITION EMPTY
	return q[head];
}
int MyQueue::back()
{
	if(empty()) throw 1; // EXCEPTION EMPTY
	return q[tail - 1];

}
bool MyQueue::empty()
{
	return head == tail;
}

bool MyQueue::full()
{
	return (tail + 1) % MAX == head;

}
