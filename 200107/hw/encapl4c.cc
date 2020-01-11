 ///
 /// @file    encapl4c.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 20:54:21
 ///

#include <cstdio>
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>


using namespace log4cpp;

using std::cout;
using std::endl;
using std::string;


class Mylogger
{
public:

	void warn(const char * msg)
	{
		string tmp = msg;
		root.warn(tmp);
	}

	void error(const char *msg)
	{
		root.error(msg);
	}

	void debug(const char *msg)
	{
		root.debug(msg);
	}

	void info(const char * msg)
	{
		root.info(msg);
	}

	static Mylogger* getInstence()
	{
		if(!logger)
			logger = new Mylogger();
		
		return logger;
	}

	void destroy()
	{
		if(logger)
			delete logger;
	}

private:
	Mylogger()
		:root(Category::getRoot()),
		 oa(new OstreamAppender("oa",&cout)),
		 rfa(new RollingFileAppender("rfa",
					 "mylog.txt",1024 * 10, 5))
	{
		root.setPriority(Priority::DEBUG);
		root.setAppender(oa);
		root.addAppender(rfa);
		PatternLayout * pl1 = new PatternLayout();
		pl1->setConversionPattern("%m%n");
		oa->setLayout(pl1);
		PatternLayout * pl2 = new PatternLayout();
		pl2->setConversionPattern("%m%n"); 
		rfa->setLayout(pl2);
	}
	~Mylogger()
	{
		Category::shutdown();		
	}

	string addinfo(const char * msg)
	{
		string s1(msg);
		string s2 = string((__FILE__, __LINE__,__FUNCTION__));
		return s2 + string("  ") + s1;
	}

	static Mylogger *logger;
	Category & root;			//实际上，运行其他函数的时候只需要调用root
	OstreamAppender * oa;		// oa rfa都秩序奥设置好，不需要保存为成员
	RollingFileAppender *rfa;
};

Mylogger * Mylogger::logger = nullptr;

int main(void)
{
	
	Mylogger * log = Mylogger::getInstence();
	log->warn("hello");


	return 1;

}
