/*find volume of a sphere with radius 10.(textbook chapter 2, page 34, question2)*/

#include <stdio.h>

int calc_rCubed(int r){
	int cubed = r*r*r;
	return cubed;
}

int main(void){

	float fractional_part = (4.0/3.0);
	float pi = 3.14;
	int r = 10;
	int rCubed = calc_rCubed(r);

	float volume = fractional_part*pi*rCubed;
	
	printf("%.2f\n",volume);



}
