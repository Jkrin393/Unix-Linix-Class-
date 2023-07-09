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
	//struct for board position. allows the game's while loop to test a direction before moving the current location or the walk. probably could have done the same thing with 2 variables instead.
	typedef struct{
		int x;
		int y;
	}BoardPosition;
	
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

	//initialize starting position

	BoardPosition curr_loc;
	curr_loc.x = rand() % 10;
	curr_loc.y = rand() % 10;
	
	//static start for debugging
	curr_loc.x = 4;
	curr_loc.y = 4;
	
	//define an array to store the coords that match directions	
	//arr[x][y] : x = row, y = col, up = {-1,0};
	int moves[4][2] = {{1,0},{-1,0},{0,-1},{0,1}}; //down, up, left right
	
	int letter_limit = 26;
	char start_letter = 'A';
	char curr_letter = start_letter;

	board[curr_loc.x][curr_loc.y] = curr_letter; 
	print_board(board);
	curr_letter++;
	
	int direction; 
	int count = 0;
	bool valid_move = true; 
	int xVal,yVal,xTest,yTest;

	while(count < letter_limit){
		//direction = rand() % 4;
		direction = 0;
		printf("Rand Direction ");
		print_direction(direction);
		printf("\n");

		xVal =  moves[direction][0]; // index 0 represents x value of the move pair - up = [-1,0]
		yVal =  moves[direction][1]; // index 1 represents y value of the move pair
		
		xTest = 0;
		yTest = 0;
		//check for positive case: new location is not out of bounds(val > 0 && <10) and the space is empty
		
		/*xTest = xVal + curr_loc.x;
		yTest = yVal + curr_loc.y;
*/		
		xTest = xVal + curr_loc.x;
		yTest = yVal + curr_loc.y;
		printf("xTest: %d, yTest: %d \n", xTest, yTest);
		if(xTest >=0 && xTest<10 && yTest >=0 && yTest<10 && board[xTest][yTest]=='.' ){
			printf("accecpted direction");
			print_direction(direction);
			curr_loc.x += xVal;
			curr_loc.y += yVal;		
			board[curr_loc.x][curr_loc.y] = curr_letter;
			curr_letter++;
	       		count++;
			print_board(board);
			
		}

		//check if a next move is possible
		int dir_count = 4;
		for(i=0;i<4;i++){
			xVal =  moves[i][0];
			yVal =  moves[i][1];
			
			if(xTest<0 || xTest>=10 || yTest <0 || yTest>=10 || board[xTest][yTest] !='.' ){
				printf("this direction tested invalid ");
				print_direction(i);
				dir_count--;
			}
						
		}
		if(dir_count== 0){
			printf("Game Over");
			break;
		}

			
	}
}
int main(){

	printf("main started");
	play_walk();

	return 0;
	


}
		/*
		if(curr_loc.x + xVal >=0 && curr_loc.x + xVal<10 && curr_loc.y + yVal >=0 && curr_loc.y + yVal<10 && board[curr_loc+xVal][curr_loc+yVal]=='.' ){
			printf("accecpted direction");

			curr_loc.x += xVal;
			curr_loc.y += yVal;		
			board[curr_loc.x][curr_loc.y] = curr_letter;
			curr_letter++;
	       		count++;
			print_board(board);
			
		}*/
		//	if(curr_loc.x + xVal <0 || curr_loc.x + xVal>=10 || curr_loc.y + yVal <0 || curr_loc.y + yVal>=10 || board[xVal][yVal] !='.' ){
