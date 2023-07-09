/* whotofile.c
 *	purpose: show how to redirect output for another program
 *	   idea: fork, then in the child, redirect output, then exec
 */
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<wait.h>

main()
{
	int	pid ;
	int	fd;

	printf("About to run who into a file\n");

	/* create a new process or quit */
	if( (pid = fork() ) == -1 ){
		perror("fork");
		 exit(1);
	}
	/* child does the work */
	if ( pid == 0 ){
		close(1);				/* close */ //this closes the standard output
		
		//check if file existis/can be written to
		if(access("userlist", F_OK) == -1){
			fd = creat( "userlist", 0644 );		/* then open */
		}
		else{
			fd = open("userlist", O_WRONLY | O_APPEND);//"a" will append to the tail of the file
		}
			
		//file opens/created successfully?
		if(fd==-1){
			perror("open error");
			exit(1);
		}

		//redirect stdout using dup2
		execlp( "who", "who", NULL );		/* and run	*/
		perror("execlp");
		exit(1);
	}
	/* parent waits then reports */
	if ( pid != 0 ){
		wait(NULL);
		printf("Done running who.  results in userlist\n");
	}
}
