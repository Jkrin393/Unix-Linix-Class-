#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define C_MIN -50
#define C_MAX 150


//arrays to store temperatures
float f_temps[C_MAX-C_MIN];
int c_temps[C_MAX-C_MIN];


int main(){
	int i;
	int num_iter = C_MAX - C_MIN + 1;	
	int c_temp = C_MIN;	
	
	for(i = 1; i<=num_iter; i++){
		f_temps[i] = (1.8*(c_temp)+32);
		printf("Farenheit: %.2f degrees, Celsius: %d degress\n", f_temps[i] ,c_temp);
		c_temp++;
		
		if(i%5==0)
			printf("\n");

		
	}
	return 0;
}
