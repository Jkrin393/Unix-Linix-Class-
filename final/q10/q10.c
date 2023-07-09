#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
	
#define is_delim(x) ((x)==' '|| (x)== '\t' || (x)=='\n')


int main(){
	char input_string[100];
	char** argv = NULL;
	int argc = 0;
	int len;
	char* cp;
	
	printf("Enter a command >>");
	fgets(input_string, sizeof(input_string), stdin);
	
	
	//count num args, split words
	cp = input_string;
	char* start;
	
	while(*cp != '\0'){
		while(is_delim(*cp)){
			cp++;
		}
		if(*cp == '\0')
			break;
		
		start = cp;
		len = 0;
		
		while(*cp != '\0' && !(is_delim(*cp))){
			len++;
			cp++;
		}

		argv = realloc(argv, (argc+1) * sizeof(char*));
		argv[argc] = malloc((len+1)*sizeof(char));
		strncpy(argv[argc] ,start, len);
		
		argc++;
	}
	argv = realloc(argv, (argc+1) * sizeof(char*));
	argv[argc] = NULL; // terminate array
	
	execvp(argv[0],argv);	
	
	for(int i = 0;i<argc;i++){
		free(argv[i]);
	}
	free(argv);
	return 0;
}
