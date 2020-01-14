#ifndef __LINEPIPLM_H__
#define __LINEPIPLM_H__

class line
{
public:
	line(int x1 = 0, int y1 = 0, 
		 int x2 = 0, int y2 = 0 );
	~line()
	{
		delete lp;
	}
	void print();
	
private:
	class line_piplm;
	
	line_piplm * lp;

};



#endif

