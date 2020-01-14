#include "linepiplm.h"
#include <iostream> // include header only when needed!
using std::cout;
using std::endl;

class line::line_piplm 
{
public:
	line_piplm(int x1, int y1, int x2, int y2):
		head(x1, y1),
		tail(x2, y2){}
	void print()
	{
		head.print();
		cout<<" ---> ";
		tail.print();
		cout<< endl;
	}

private:
class point
{
public:
	point(int xx, int yy):
		x(xx),
		y(yy){}
	void print()
	{
		cout<<"( "<< x << " , "
			<< y <<" )";
	}
private:
	int x;
	int y;

};
private:
	point head;
	point tail;

};

line::line(int x1, int y1,
		   int x2, int y2):
	lp(new line_piplm(x1, y1, x2, y2)){}
		
void line::print()
{
	lp->print();
}



