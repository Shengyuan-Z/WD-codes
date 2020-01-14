 ///
 /// @file    circle.cc
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-13 21:34:45
 ///
 
#define PI 3.14

#include <iostream>
using std::cout;
using std::endl;

class Circle
{
public:
    Circle():_r(0){}
    Circle(double r):_r(r){}

    double getArea() {return PI * _r * _r;}
    double getPerimeter() {return 2 * PI * _r;}
    void show()
    {
        cout<< "r = " << _r << endl
            << "Pirimeter =  " << getPerimeter() << endl
            << "Area = " << getArea() << endl;
    }
private :
    double _r;
};

class Cylinder
:public Circle
{
public:
    Cylinder(double r, double h):
       Circle(r),
       _h(h){}
    
    double getVolume(){return _h * getArea();}
    void showVolume(){
        show();
        cout<< "Height = " << _h << endl;
        cout<< "Volume = " << getVolume() << endl;
    }
private: 
    double _h;
};


int main(void)
{
    Cylinder cyl(3, 4);
    cyl.showVolume();
    
    return 0;
}
