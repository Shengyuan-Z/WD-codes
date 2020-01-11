#include"dllist.h"
#include<iostream>

using std::cout;
using std::endl;


List::List()
:_size(0)
{
	Node * ohead = new Node ;
	ohead->data = 0;
	ohead->pre = nullptr;
	ohead->next = nullptr;
	_head  = ohead;
	_tail  = ohead;	
}


List::~List()
{
	Node * tmp;
	while(_head->next != nullptr) 
	{
		tmp = _head -> next;
		_head->next = tmp->next;
		delete tmp;
	}
	delete _head;
}

void List:: push_back(int value)
{
	Node * nnode = new Node{value, _tail, nullptr};
	_tail->next = nnode;
	_tail = nnode;
	_size++;
}
void List::push_front(int value)
{	
	Node * nnode = new Node{value, _head, _head->next};
	if (!empty()) _head->next->pre = nnode;
	_head->next = nnode;
	_size++;
}

void List::pop_back()
{
	if(empty())	
	{
		cout<<"The list is empty"<<endl;
		return ;
	}
	Node * tmp = _tail;
	_tail = _tail->pre;
	_tail->next = nullptr;
	delete tmp;
	_size--;
}

void List::pop_front()
{
	if(empty())	
	{
		cout<<"The list is empty"<<endl;
		return ;
	}
	Node * tmp = _head->next;
	if (tmp->next)	tmp->next->pre = _head;
	_head->next = tmp->next;
	delete tmp;
	_size--;
}
	
void List::insert(Node *p , int value)
{
	Node * aim = find(p);
	if (aim == nullptr) 
	{
		cout<<"This node does not belong to the list."<<endl;
		return ;
	}
	Node* nnode = new Node{ value,nullptr,nullptr };
	insert(aim, nnode);
}
	 		
void List::erase(int data)
{
	Node * aim = find(data);
	if (aim == nullptr) 
	{
		cout<<"This node does not belong to the list."<<endl;
		return ;
	}
	erase(aim);
}
	 		
void List::display() const
{
	Node * tmp = _head->next;
	if (!tmp) 
	{
		cout << endl;
		return ;
	}
	while (tmp->next)
	{
		cout << tmp->data << "\t->";
		tmp = tmp->next;
	}
	cout<<tmp->data<<endl;
}
	 	
Node* List::find(int dat)
{
	Node * it = _head->next;
	while(it)
	{
		if(it->data == dat) return it;
		it = it->next;
	}
	return nullptr;
}

Node * List:: find(Node * p)
{	
	Node * it = _head->next;
	while(it)
	{
		if(it == p) return it;
		it = it->next;
	}
	return nullptr;
}

Node* List::insert(Node * pos, Node * nnode)
{
	nnode->next = pos;
	nnode->pre = pos->pre;
	pos->pre->next = nnode;
	pos->pre = nnode;
	_size++;
	return nnode;
}


void List::erase(Node *aim)
{
	Node * tmppre = aim->pre;
	tmppre->next = aim->next;
	aim->next->pre = tmppre;
	delete aim;
	_size--;
}
