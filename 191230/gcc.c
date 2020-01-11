 /// @file    gcc.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-05 15:05:45
 ///
#include<stdio.h> 
#define NUM 2+4
 
int sq(int a)
{	
	return a*a;
}

int main(void)
{
	int i = sq(NUM);
	printf("rslt= %d \n",i);
	return 0;
}
