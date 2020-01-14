 ///
 /// @file    singleton1.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-11 20:10:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class singleton
{
public:
	static singleton * getInstance()
	{
		if(nullptr == pIns)
			pIns = new singleton();

		return pIns;
	}


private:
	singleton(){}//这两个函数会被调用！不能不实现！
	~singleton(){}
	class autoRl
	{
	public:
		~autoRl()
		{
			if(pIns) 
				delete pIns;
			cout<<"~autoPl()"<< endl;
		}
	};
private:
	static autoRl ar;	
	static singleton * pIns;
	
};

singleton * singleton::pIns = getInstance();
singleton::autoRl singleton::ar;//调用默认构造函数

void test()
{
	singleton * s1 = singleton::getInstance();
	singleton * s2 = singleton::getInstance();

	cout<<"s1: " << s1 << endl
		<<"s2: " << s2 <<endl;

}


int main(void)
{
	test();

	return 0;
}
