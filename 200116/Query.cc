 ///
 /// @file    Query.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-19 17:25:13
 ///

#include "Query.h"
#include <fstream>
#include <sstream>
using std::ifstream;
using std::cout;
using std::endl;
using std::istringstream;


TextQuery::TextQuery(const string & filename)
: file(new vector<string>)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << "Opening fails" << endl;
        return;
    }
    string line;
    string word;
    int num = 0;
    while(getline(ifs, line))
    {
        file->push_back(line);
        istringstream iss(line);
        num = file->size() - 1; //num of row
        while(iss >> word)
        {
            auto & lines = wm[word]; //creat it when this word doesn't occur before 
            if( !lines )
                lines.reset(new set<int>);
            lines->insert(num);
        }
    }
}

QueryResult TextQuery::query(const string & st) const
{
    if(wm.find(st) == wm.end())
    {
        static shared_ptr<set<int>> nodata;
        return QueryResult(st, nodata, file);
    }
    auto loc = wm.find(st);
    // reutrn QueryResult(st, wm[st], file) // why doesn't this work????
    return QueryResult(st, loc->second, file);
}

ostream & print(ostream & os, const QueryResult & qr)
{
    os << qr.sought << " occurs " << qr.num_lines->size() 
       << " times. " << endl;
    for (auto num : *qr.num_lines)
        os << "\t(line " << num + 1 << ") "
           << * (qr.file->begin() + num) << endl;
    return os;
}






