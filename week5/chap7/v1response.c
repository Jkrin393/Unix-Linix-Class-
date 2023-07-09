#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <time.h>
#include <signal.h>
#include <float.h>

#define NANOSECONDS 1000000000

struct timespec responses[10];
float response_times[10];
float max = FLT_MAX;
float min = FLT_MIN;
float avg;




int main(){
	srand(time(NULL)); //set seed for random time
		
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
	//	wait_time.tv_sec = rand() % 10;
		wait_time.tv_sec = 3;
		
		nanosleep(&wait_time, NULL ); // nanosleep takes a timepec struct as the first arguments, and a handler interrupt as the second)

		int game_num = rand()%10; 
		mvprintw(0,0,"The numbder is: %d\n", game_num);//move the rand num to the screen buffer
		refresh();//push buffer to screen, refresh buffer
		//start timer
		clock_gettime(CLOCK_REALTIME, &g_start); //gettime 

		//printf("start sec: %ld and nano: %ld \n", g_start.tv_sec, g_start.tv_nsec);
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
		
		//if somehow nanoseconds go over the limit add this check in case
		if(ns_diff >= NANOSECONDS){
			s_diff ++;
			ns_diff =-NANOSECONDS;
		}
		
		response_times[i] = s_diff + (ns_diff/NANOSECONDS);
		
		//save response time to a timespec struct and add to array -- no need for all this, just add seconds + ns and store as flaot arr
		//struct timespec resp_time;
		//resp_time.tv_sec = s_diff;
		//resp_time.tv_nsec = ns_diff;
		//responses[i].tv_sec = resp_time.tv_sec;			
		//responses[i].tv_nsec = resp_time.tv_nsec;			

		
	}

	//need to not overlap screen position
/*	for(i=0;i<10;i++){
		mvprintw(i,0, "test#:%d   seconds: %ld, nanos: \n", i, responses[i].tv_sec,  responses[i].tv_nsec);	
		refresh();
	}*/
	
	//turn settings back to default and close curses window
	echo(); //enable echo
	nocbreak();
	nodelay(stdscr, FALSE);// sets default line buffering
//	getch();
	flushinp();
	endwin();
	exit(1);

return 0;
}




