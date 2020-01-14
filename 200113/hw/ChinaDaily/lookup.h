 ///
 /// @file    lookup.h
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-14 15:29:50
 ///
#ifndef LOOKUP_H
#define LOOKUP_H

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <locale>
using std::map;
using std::set;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::transform;
using std::cerr;
using std::cout;
using std::endl;

string wash(string);
class Lookup
{
public:
    void read(string filename);
    void query(const string & word);

private:
    void read_word(int num, const string & line);// unnecessary to carry the data inside the class
private:
    vector<string> lines;
    map<string, int> dict;
    map<string, set<int> > wordNumbers;
};


#endif

