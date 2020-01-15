 ///
 /// @file    test.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-15 17:10:36
 ///

#include "geometry.h"

using namespace Geometry;

void test()
{
    Circle ci(3);
    Cylinder cy(3, 4);
    ci.show();
    cy.show();

}

int main(void)
{
    test();
    return 0;
}
