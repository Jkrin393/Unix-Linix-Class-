#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFERSIZE 3

int main(int av, char* args[]){
	FILE* input_file;
	char buffer[BUFFERSIZE];
	size_t read_bytes;
	char* file_name = args[1];

	input_file = fopen(args[1],"r");
	
	if(input_file == NULL){
		printf("File error: cant open %s\n",input_file);
		exit(1);
	}

	//read some bytes
	int i;

	while((read_bytes = fread(buffer, sizeof(char), BUFFERSIZE-1,input_file)) >0){
		if(access(file_name, R_OK)!= 0){
			printf("File error: access lost %s\n",file_name);
			break;
		}
		read_bytes = fread(buffer, sizeof(char), BUFFERSIZE-1,input_file);
		printf("%i bytes read in loop \n",read_bytes);
		sleep(10);
	}
	

	/*
	read_bytes = fread(buffer, sizeof(char), BUFFERSIZE-1,input_file);
	printf("%i bytes read \n",read_bytes);
	fclose(input_file);
	return 0;
	*/
	return 0;
}
