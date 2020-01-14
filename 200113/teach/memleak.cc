 ///
 /// @file    memleak.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-13 10:06:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int * p = new(int)(1);
	cout << *p <<endl;

	return 0;
}
