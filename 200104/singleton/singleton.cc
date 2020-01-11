 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 10:48:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class singleton
{
public:
	static singleton* getInstance()
	{	
		if(st == nullptr) 
			st = new singleton();	
		return st;
	}
	static void destroy()
	{
		if(st != nullptr) 
			delete st;
	}
private:
	singleton(){}
	~singleton(){}
	static singleton * st;

};

singleton* singleton::st = nullptr;

//singleton s4; //error

int main(void)
{
	//singleton s1;//error
	//singleton * s2 = new singleton();//error
	singleton * s3 = singleton::getInstance();
	singleton * s4 = singleton::getInstance();
	if (s4 == s3) cout<<"Good"<<endl;
	
	singleton::destroy();
	
	return 0;

}
