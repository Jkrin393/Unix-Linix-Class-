//ex 6, pg 525. Write a function to perform a bitwise shift on an unsigned short: unsigned short swap_bytes(unsigned short i);
//
//
//
#include <stdio.h>
#include <stdlib.h>


#define MAX_SHORT = 65535

unsigned short swap_bytes(unsigned short i){

	unsigned short left_shift;
	unsigned short right_shift;

	left_shift = i<<8;
	right_shift = i>>8;
	

	//printf("left: %hx \n", left_shift);
	//printf("right: %hx \n", right_shift);
	//printf("sum: %hx \n", left_shift+right_shift);

	return (left_shift + right_shift);	
}

unsigned short line_swap_bytes(unsigned short i){

	return (i<<8 | i>>8);//pipe for bitwise operatins combined previous 2 operations
		
}




int main(){

	unsigned short input_num;
	unsigned short swapped_num;
	
	printf("Please enter a number: ");
	scanf("%hx", &input_num);

	swapped_num = swap_bytes(input_num);
	printf("Multi line swap: %hx \n", swapped_num);

	swapped_num = line_swap_bytes(input_num);
	printf("Single line swap: %hx \n", swapped_num);
	return 0;
}

