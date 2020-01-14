 ///
 /// @file    singleton1.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-11 20:10:45
 ///
 
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
 
class singleton
{
public:
	static singleton * getInstance()
	{
		pthread_once(&once, init);	
		return pIns;
	}
	static void init()
	{
		pIns = new singleton();
		atexit(destroy);
	}
	static void  destroy() 
	{
	//	if (pIns)     //在init只运行一次的情况下，可以省略，因为一定为true
			delete pIns;
		cout<<"destroy()"<<endl;
	}


private:
	singleton(){}//这两个函数会被调用！不能不实现！
	~singleton(){}

private:
	static singleton * pIns;
	static pthread_once_t once;
};
singleton * singleton::pIns = nullptr;  //singleton::getInstance(); // This doesn't work.
pthread_once_t singleton::once = PTHREAD_ONCE_INIT;

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
