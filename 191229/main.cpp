#include <iostream>
#include <vector>
using namespace std;

void printMul();
void printShape();
vector<int> commonEle2 (int[], int, int[], int);
vector<int> commonEle3(int[], int[], int[]);
vector<int> max12(int[]);
vector<int> mainEle(int[]);
int findRpt(int[]);
//int lengthof(int a[]){return sizeof(a)/sizeof(a[0]);}



int main()
{
	//printShape();
	int a[] = {1,3,4,5,6,7,8,9};
	int b[] = {1,2,3,4,5,6};
	vector<int> c = commonEle2(a,sizeof(a)/sizeof(a[0]),b,sizeof(b)/sizeof(b[0])); 
	for(int i = 0; i < c.size(); i++) cout<<c[i]<<"\t";
	cout<<endl;
	return 0;
}

void printMul()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
}

void printShape()
{
	// Shape 1
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++) cout << " ";
		for (int j = 0; j < i; j++) cout << "* ";
		cout << endl;
	}
	for (int i = 0; i < 5; i++) cout << "* ";
	cout << endl;
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < 5 - i; j++)cout << ' ';
		for (int j = 0; j < i; j++) cout << "* ";
		cout << endl;
	}
	cout<<endl;
	// Shape 2
	cout<<"    *"<<endl;
	for(int i = 1; i < 5; i++)
	{
		for(int j = 0; j < 5-i-1; j++) cout<<' ';
		cout<<"*";
		for(int j = 0; j < 2*i-1; j++) cout<<' ';
		cout<<"*";
		cout<<endl;
	}
	for(int i = 3; i >0; i--)
	{
		for(int j = 0; j < 5-i-1; j++) cout<<' ';
		cout<<"*";
		for(int j = 0; j < 2*i-1; j++) cout<<' ';
		cout<<"*";
		cout<<endl;
	}
	cout<<"    *"<<endl<<endl;
	// Shape 3
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3-i; j++) cout<<' ';
		for(int j = 0; j < i+2; j++) cout<<"* ";
		for(int j = 0; j < 8-i*2; j++) cout<<' ';
		for(int j = 0; j < i+2; j++) cout<<"* ";
		cout<<endl;
	}
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 10 - i; j++)cout << ' ';
		for (int j = 0; j < i; j++) cout << "* ";
		cout << endl;
	}
	cout<<endl;
}

vector<int> commonEle2(int a[], int a_len, int b[], int b_len)
{
	int i = 0, j = 0;
	vector<int> *rslt = new vector<int>;
	while(i < a_len  && j < b_len)
	{
		if(a[i]== b[j]) rslt->push_back(a[i]);
		while(a[i] < b[j]) i++;
		while(a[i] > b[j]) j++;
	}
	return *rslt;
}

vector<int> commonEle3(int[], int[], int[]);
vector<int> max12(int[]);
vector<int> mainEle(int[]);
int findRpt(int[]);




