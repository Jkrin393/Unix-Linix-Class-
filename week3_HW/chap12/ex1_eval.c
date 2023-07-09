#include <stdlib.h>
#include <stdio.h>

void main(){
	int a[] = {5,15,34,54,14,2,52,72};
	int* p = &a[1];
	int* q = &a[5];

	printf("a: %d \n", *(p+3));
	printf("b: %d \n", *(q-3));
	printf("c: %d \n", (q-p));
	printf("d: %d \n", p<q);
	printf("e: %d \n", *p<*q);


}
