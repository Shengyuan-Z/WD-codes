 ///
 /// @file    test.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-13 22:57:58
 ///
 
 
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
using std::map;
using std::set;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;
 
int test0()
{
    string a("as dc vf dc");
    string b("fds sdffs vdf");
    istringstream iss(a);//initialize with string 
    //ostringstream oss;
    iss.str(b);
    string word; // view word as memory !!! so choose iss rather than oss 
    while(iss >>  word, !iss.eof()) //iss give the word to word 
    {
       // word = oss.str();
        //iss>>word;
        cout<<word<<endl;
    }
    return 0;
}

void test1()
{
    string s("&");
    if(!isalpha(s[0])) cout<< "yes"<<endl;

}


int main()
{
    test1();
    return 0;
}
