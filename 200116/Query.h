 ///
 /// @file    Query.h
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-19 17:16:13
 ///
#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory>
#include <set>
#include <vector>
#include <map>
#include <iostream>
using std::string;
using std::shared_ptr;
using std::set;
using std::vector;
using std::map;
using std::ostream;


class QueryResult;

class TextQuery
{
public:
    TextQuery(const string & filename);
    QueryResult query(const string & )const;

private:
    shared_ptr< vector<string> >  file;
    map< string, shared_ptr< set<int> > > wm;

};



class QueryResult
{
friend ostream& print(ostream &, const QueryResult &);
public:
    QueryResult(string s, shared_ptr<set<int>> num, 
                shared_ptr<vector<string>> f)
        :sought(s), num_lines(num), file(f){}

private:
    string sought;
    shared_ptr<set<int>> num_lines;
    shared_ptr<vector<string>> file;
};
ostream & print(ostream &, const QueryResult &);


#endif

