 ///
 /// @file    singleton1.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-11 20:10:45
 ///
 
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
 
class singleton
{
public:
	static singleton * getInstance()
	{
		if(nullptr == pIns)
		{
			pIns = new singleton();
			atexit(destroy);
		}
		return pIns;
	}
	static void  destroy() 
	{
		if (pIns)
			delete pIns;
		cout<<"destroy()"<<endl;
	}


private:
	singleton(){}//这两个函数会被调用！不能不实现！
	~singleton(){}

private:
	static singleton * pIns;
	
};

singleton * singleton::pIns = getInstance();

void test()
{
	singleton * s1 = singleton::getInstance();
	singleton * s2 = singleton::getInstance();

	cout<<"s1: " << s1 << endl
		<<"s2: " << s2 << endl;

}


int main(void)
{
	test();

	return 0;
}
