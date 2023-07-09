#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10
int main(){


	int moves[4][2] = {{1,0},{-1,0},{0,-1},{0,1}}; //down, up, left right

	int i,j;

	int x, y, xVal, yVal;

	x = 4;
	y = 4;

	printf("x val: %d, y val : %d",x,y);

	int move;
	move = 1;
	//move the character up one space (-1 x val)
	xVal = moves[move][0];
	yVal = moves[move][1];

	x += xVal;
	y += yVal;

	printf("x val: %d, y val : %d",x,y);


}
