 ///
 /// @file    test.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-19 17:16:38
 ///
 
#include "Query.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
    string filename("china_daily.txt");
    string word("link");
    TextQuery tq(filename);
    QueryResult qr = tq.query(word); 
    print(cout, qr);

    return 0;
}
