#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

int c_count = 0;

void child_handler(int sig_code){
	int status;//store value returned by wait()
	pid_t child_pid;	

	//wait for child process. wait will return -1 on error(no message) or PID on success
	child_pid = wait(&status);
	
	if(status==-1){
		printf("error in wait function, child returned -1");
		exit(1);
	} 
	c_count++;
		
}//end handler

int main(){

	//set signal handler as the child_handler function
	
	signal(SIGCHLD, child_handler);
	
	int input_pid_num;
	int i;	
	printf("Pick a number of child processes: ");
	scanf("%d", &input_pid_num);

	//fork the current process to create child processes 
	pid_t pid;
	for(i = 0; i<input_pid_num; i++){
		pid = fork();//fork returns a child PID of 0 on successful fork 
		if(pid == 0){
			printf("fork successful\n");
			sleep(5); // child function is sleep()
			exit(0);//end child process
		}
		else if(pid == -1){
			perror("Fork error");
			exit(1);
		}
	}//for loop	


	while(c_count < input_pid_num){
		printf("waiting for all my children..sigh...\n");
		sleep(1);
	}

	printf("All children fiinshed, exiting now\n");

	


}//end main
