#ifndef DLLIST_H
#define DLLIST_H

struct Node
{
	int data;
	Node * pre;
	Node * next;
}; 
	 
class List
{
// A unused node serves as the original head when the class is initialized.
public:
	List();
	~List();
	 		
	void push_back(int);
	 		
	void push_front(int);

	void pop_back();

	void pop_front();
	 		
	void insert(Node *, int);
	 		
	void erase(int);	 			 		
	 		
	void display() const;
	 	
	Node * find(int);
	 
private:
	Node * find(Node * );	
	Node * insert(Node * pos, Node * nnode);//insert in front of pos	
	void erase(Node *);		
	bool empty(){return _head == _tail;}
	 		
private:
	Node * _head;
	Node * _tail;
	int    _size;
};		


#endif
