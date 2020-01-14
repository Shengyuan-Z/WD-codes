 ///
 /// @file    test.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-11 19:45:39
 ///
 
#include "linepiplm.h"
#include <iostream>
using std::cout;
using std::endl;
 

void test0()
{
	line l1;
	line l2(1,2,3,4);

	l1.print();
	l2.print();
}


int main(void)
{
	test0();

	return 0;

}
