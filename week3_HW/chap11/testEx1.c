#include<stdlib.h>
#include <stdio.h>

void main(){
	int i;
	int* p;
	i = 22;
	*p = i;
	printf("a: %d \n",*p);
	printf("b: %d \n",&p);
	printf("c: %d \n",*&p);
	printf("d: %d \n",*&p);
//	printf("e: %d \n",*i);
	printf("f: %d \n",&i);
	printf("g: %d \n",*&i);
//	printf("h: %d \n",&*i);
	
}

