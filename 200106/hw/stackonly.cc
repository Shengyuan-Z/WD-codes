 ///
 /// @file    stackonly.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 22:20:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class stackonly
{
public:
	stackonly(){}

private:
	void* operator new(size_t sz);
	void operator delete(void * p);

};



int main(void)
{
	stackonly s1;
//	stackonly * s2 = new stackonly();


	return 0;

}
