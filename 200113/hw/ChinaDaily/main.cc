 ///
 /// @file    main.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-13 22:24:36
 ///
#include "lookup.h"


void test()
{
    string filename("china_daily.txt");
    string testword("is");
    Lookup lu;
    lu.read(filename);
    lu.query(testword);

}


int main(void)
{
    test();
    return 0;
}
