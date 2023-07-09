#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>

#define NUM_PROCESSES 2

int child_process(int pid_num){
	printf("I am child %d! \n", pid_num+1);
	return 0;		
}



int main(){
	pid_t pid;
	int i;
	//create child procceses in a loop

	for(i=0;i<NUM_PROCESSES;i++){
		pid = fork();
		//check fork returned successfully		
		if(pid <0){
			perror("fork issue\n");
			exit(1);
		}	
		//dynamically print process num 
		else if(pid == 0){
			child_process(i);
			break;
		}
	}
	
	//parent waits for all children to finish
	int child_count = 0;
	while(child_count<2){
		wait(NULL);
		child_count++;
	}

	return 0;
}
