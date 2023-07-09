#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char output_string[50];

char* string_reversed(char* string){
	
	int len = strlen(string);
	int i;
	
	for(i = 0;i<len;i++){
		output_string[i] = string[len-i-1];
	}	
	

	return output_string;
}

int main(){
	
	
	char input_string[50];// = "Two words";
	printf("Please enter the string to reverse word: ");
	fgets(input_string, sizeof(input_string), stdin);
	
	
	printf("%s\n",	string_reversed(input_string));
	return 0;
}
