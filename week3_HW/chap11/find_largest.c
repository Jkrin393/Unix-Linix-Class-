#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//when passed an array of length n, the function returns a pointer to the largest element
int *find_largest(int a[], int n){
	int* largest = malloc(sizeof(int));
	*largest = -INT_MAX; // defined word for largest Integer value
	
//	printf("Largest: %d \n", largest );
	int i;

	
	for(i=0;i<n;i++){
		if(a[i]> *largest){
			*largest = a[i];
		}
	}

	
	printf("Largest Value: %d \n", *largest );
	printf("Memory Address: %d \n", largest );
	
	free(largest);
	return largest;		

	
	
}//end largest


int main(){
	int arr[10];

	int i;
	int arr_len;
	arr_len = sizeof(arr)/sizeof(arr[0]);

	for(i=0;i<arr_len;i++){
		arr[i] = i+1;
	}

	arr[5] = 1000;

	find_largest(arr, arr_len);	





}//end main
