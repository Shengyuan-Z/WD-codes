 ///
 /// @file    test.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 10:15:08
 ///
 
#include <stdio.h>
 
int main(void)
{
	int arr[100];
	int* p = & arr + 1;
	printf("%d\n",(int)(p - arr));

	return 0;
}
