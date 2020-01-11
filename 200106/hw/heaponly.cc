 ///
 /// @file    heaponly.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 22:33:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class heaponly
{
public:
	heaponly(){}
	void destroy(){delete this;}

private:
	~heaponly(){}

};



int main(void)
{
	//heaponly ho1; // Should be error
	heaponly * ho2 = new heaponly();
	ho2->destroy();


	return 0;
 
}
