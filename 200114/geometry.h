 ///
 /// @file    geometry.h
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-15 16:33:37
 //
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;


namespace Geometry // better to put the series into one namespace  
{
    const double PI = 3.14;

    class Figure
    {
    public:
        virtual double getArea( ) = 0; // unnecessary to implement pure virtual functions
        virtual string getName( ) = 0;
        virtual void show() = 0;
    protected: // set it protected for the derived class' using 
        string name;

    };

    class Circle
    : protected Figure 
    {
    public:
        Circle() :_r(0){ name = "Circle"; } //  public & protected 
        Circle(double r):_r(r){ name = "Circle"; }
        double getRadius(){return _r;}
        double getPerimeter(){return 2 * _r * PI; }
        virtual double getArea(){ return PI * _r * _r; }//set it virtual to implement poly 
        virtual string getName(){ return name; }
        void show()
        { 
            cout << name << endl
                 << "Radius = "<< getRadius() << endl 
                 << "Perimeter = " << getPerimeter() << endl 
                 << "Area = " << getArea() <<endl;
        }
    protected:
        double _r;
    };

    class Cylinder
    : protected Circle 
    {
    public:
        Cylinder(){name = "Cylinder";}
        Cylinder(double r, double h):Circle(r),_h(h){ name = "Cylinder"; }
        double getArea(){return 2 * PI * _r * _r + PI * 2 * _r * _h;}
        string getName() {return name;}
        double getHeight(){return _h;}
        double getVolume(){return PI * _r * _r * _h;}
        void show()
        { 
            cout << name << endl
                 << "Height = "<< getHeight() << endl 
                 << "Area = " << getArea() << endl 
                 << "Volume = " << getVolume() <<endl;
        }

    private:
        double _h;
    };




}
