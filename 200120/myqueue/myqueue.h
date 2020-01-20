 ///
 /// @file    myqueue.h
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-20 22:10:16
 ///
#ifndef MYQUEUE_H
#define MYQUEUE_H 


#include <iostream>
using std::cout;
using std::endl;

template <class T, int max = 10>
class Queue
{
    Queue():front(-1),back(0),q(new T(max)){}
    bool empty(){return (back - front)}
    void insert(int,T);
    


private: 
    int front;
    int back;
    T* q;

};









#endif 
