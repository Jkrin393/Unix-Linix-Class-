#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <time.h>
#include <signal.h>
#include <float.h>

#define NANOSECONDS 1000000000

int main(){
	srand(time(NULL)); //set seed for random time
	float response_times[10];
	float r_max = FLT_MIN;
	float r_min = FLT_MAX;
	float total;
	float avg;
		
	//initialize screen, turn off echo, character buffering, and delay time before process continues
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);


	//start timer at current time, record end time, calc difference
	struct timespec	g_start; // timespec comes from the time.h and has members tv_sec and tv_nsec
	struct timespec g_end;
	int i;	
	for(i=0;i<10;i++){
		
		clear();
		printw("get ready!");	
		refresh();		
	
		//wait for a random time up to 10 seconds
		struct timespec wait_time;
		wait_time.tv_sec = rand() % 10;
	//	wait_time.tv_sec = 3;
		
		nanosleep(&wait_time, NULL ); // nanosleep takes a timepec struct as the first arguments, and a handler interrupt as the second)

		int game_num = rand()%10; 
	//	int game_num = 1; 
		mvprintw(0,0,"The numbder is: %d\n", game_num);//move the rand num to the screen buffer
		refresh();//push buffer to screen, refresh buffer
		//start timer
		clock_gettime(CLOCK_REALTIME, &g_start); //gettime 

		//read and test response
		int input;
		input = getch(); //gets the ascii  value of the number
	
			while(input != '0' + game_num){
				input = getch();
			}
		clock_gettime(CLOCK_REALTIME, &g_end);

		
		//need to consider startings nanoseconds smaller than ending amount

		float s_diff;
		float ns_diff;
		
		s_diff = (g_end.tv_sec - g_start.tv_sec);
		ns_diff = (g_end.tv_nsec - g_start.tv_nsec); 
		
		if(ns_diff < 0){
			s_diff--;
			ns_diff += NANOSECONDS;
		}
		
		
		//set arr value to response time		
		response_times[i] = s_diff + (ns_diff/NANOSECONDS);

		//test for new max and new min
		if(response_times[i] > r_max){
			r_max = response_times[i];
		}
		
		if(response_times[i] < r_min){
			r_min = response_times[i];
		}

		total += response_times[i];


		//mvprintw(0,0, "test#:%d  time:%.2f \n", i, response_times[i]);	
		refresh();
		
	}

	//need to not overlap screen position
//	for(i=0;i<10;i++){
//		mvprintw(i,0, "test#:%d  time:%.2f \n", i, response_times[i]);	
//		refresh();
//	}

	avg = total / 10.00;
	
	mvprintw(0,0, "Max:%.2f  Min:%.2f, Avg: %.2f \n",  r_max, r_min, avg);	
	//turn settings back to default and close curses window
	echo(); //enable echo
	nocbreak();
	nodelay(stdscr, FALSE);// sets default line buffering
	getch(); //waits for a character before exiting program
	flushinp();
	endwin();
	exit(1);

return 0;
}




