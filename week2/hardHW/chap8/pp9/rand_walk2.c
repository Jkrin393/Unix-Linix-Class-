#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

void print_direction(int dir){
	
	if(dir == 0){
		printf("Down: \n");
	}

	if(dir == 1){
		printf("Up: \n");
	}

	if(dir == 2){
		printf("Left: \n");
	}

	if(dir == 3){
		printf("Right: \n");
	}



}

void print_board(char arr[SIZE][SIZE]){
	int i,j;
	
	printf("\n");
	for (i = 0;i<SIZE; i++){
		for(j = 0;j<SIZE; j++){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");

}

void play_walk(){
	
	//seed our random number generator
	srand((unsigned) time(NULL));
	
	int i,j;
	char board[SIZE][SIZE];
	
	//initialize array to represent the starting  board
	for (i = 0;i<SIZE; i++){
		for(j = 0;j<SIZE; j++){
			board[i][j] = '.';
		}
	}

	//define an array to store the coords that match directions	
	//arr[x][y] : x = row, y = col, up = {-1,0};
	int moves[4][2] = {{1,0},{-1,0},{0,-1},{0,1}}; //down, up, left right
	
	int letter_limit = 26;
	char start_letter = 'A';
	char curr_letter = start_letter;

	int direction;//used to get a rand value for direction of next move 
	int count = 1; // first letter is alraedy assigned
	bool valid_move = true; 
	int xVal,yVal,xTest,yTest;
	int xMov, yMov;
	
	xVal = 4;
	yVal = 4;
	board[xVal][yVal] = curr_letter;
	curr_letter++;
	print_board(board);
	
	int newX, newY;// variable to store the value of x and y after a move
	int limit = 4;
	int possible_moves;
	while(count < letter_limit){
	
		//check if move is possible from current location
		possible_moves = 0;
		for(i=0;i<4;i++){
			xMov = moves[i][0];//lookup x movement value
			yMov = moves[i][1];//lookup y movement value
			newX = xVal + xMov;
			newY = yVal + yMov;
			//printf(" New X: %d, New Y %d \n",newX,newY);
			//printf(" Xval: %d, YVal %d \n",xVal,yVal);
			
			
			if( newX >=0 && newX <10 && newY>=0 && newY<10 && board[newX][newY] == '.'){
				possible_moves++;
			}
		}
		if(possible_moves ==0){
		
			printf("No moves left...Game Over\n");
			exit(0);
		}
		
		if(possible_moves){
		
			direction =rand() % 4;//choose rand direction
			xMov = moves[direction][0];//lookup x movement value
			yMov = moves[direction][1];//lookup y movement value
			

			newX = xVal + xMov;
			newY = yVal + yMov;	
			//check if direction leads to a valid move
			if(newX >=0 && newX <10&& newY>=0 && newY<10 &&  board[newX][newY] == '.'){
				//add move to current location
				xVal = newX;
				yVal = newY ;
				board[xVal][yVal] = curr_letter;
				curr_letter++;
				count++;
				print_board(board);
			
			}
		
		
		
		}//if possible move
		
		
	}//while loop
	printf("No leters left..Winner!\n");
	
}//function

int main(){

	printf("main started \n");
	play_walk();

	return 0;
	


}
