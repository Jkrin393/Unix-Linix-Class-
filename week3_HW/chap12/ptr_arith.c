#include <stdlib.h>
#include <stdio.h>

#define LEN 10

//len = num of columns, n = size of array(rows)
int sum_2d_arr(const int a[][LEN], int n){

	int sum = 0;
	int i;
	const int* curr = &a[0][0];
	const int* end = &a[n][0];


	//while(pt for current < end pointer?>
	while(curr < end){
		sum += *curr;
		curr++;
	}

	return sum;
}

void main(){
	int input_arr[5][LEN];
//	int count = 0;
	int i,j;
	for(i = 0;i<5;i++){
		for(j=0;j<LEN;j++){
			input_arr[i][j] = 1;
//			count++;
		}

	}

	int sum = sum_2d_arr(input_arr, 5);

	printf("Sum: %d \n",sum);
//	printf("Count: %d \n",count);


}
