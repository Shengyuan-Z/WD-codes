 ///
 /// @file    bible_reader.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 22:45:07
 ///
 
#include <iostream>
#include <fstream>
//#include <ifstream>
//#include <ofstream>
#include <string.h>
#include <map>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;


class Dictionary
{
public:
	Dictionary(){}
	void read(const string & filename); 
	void store(const string & filename);

private:
	map<string,int> dict;
};

void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cerr<<"ifstream open "<<filename<<" error\n";
		return;
	}
	string word;
	while(ifs>>word, !ifs.eof())  //加上if.eof()的判断
	{
		if(!isdigit(word.c_str()[0]))// 判断是否为数字
			{
				dict[word]++;
			}
	}
	ifs.close();
}

void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	ofs.precision(15);
	ofs<<"-----------------"<<endl;
	for(map<string,int>::iterator it = dict.begin();
			it != dict.end();
			it++)
	{
	ofs<<"|"<<it->first<<" \t"<<it->second<<" \t|"<<endl;
	}
	ofs<<"-----------------"<<endl;
	ofs.close();
}
int main(void)
{
	Dictionary bible_reader;
	string bible("The_Holy_Bible.txt");
	string stat("Statistics_of_Bible.txt");
	bible_reader.read(bible);
	bible_reader.store(stat);


	return 0; 
}
