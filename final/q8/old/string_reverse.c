#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char output_string[50];

char* string_reversed(char* string){
	
	int len = sizeof(string)/sizeof(char);
	int i;

	for(i = 0;i<len;i++){
		output_string[i] = string[len-i-1];
	}	
	

	return output_string;
}

int main(){
	
	
	char input_string[50];
	printf("Please enter the string to reverse word: ");
	scanf("%s", input_string);
	int i;
		
	printf("%s\n",	string_reversed(input_string));
//	for(i = 0;i<strlen(output_string);i++){
//		printf("%c: \n", output[i]);
//	}	
	return 0;
}
