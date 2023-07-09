#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void read_word(int counts[26]){
	char word[100]; //phrase can have a max of 100 characters
	int i;
	char curr_letter;
	
	//promt for a phrase, remove spaces or
	printf("Please enter a word: ");
	
	//read through the input one character at a time until new line is found
	//getchar returns one letter at time from the stdin
	for(i=0; i<100 ;i++){
		curr_letter = getchar();
		if(isalpha(curr_letter) && curr_letter != '\n'){
			word[i] = tolower(curr_letter);
			counts[word[i]-'a']++;	
		}
		if(curr_letter == '\n'){
			word[i] = curr_letter;
			break;
		}
	}

	for(i=0;word[i]!='\n';i++){
		printf("%c", word[i]);
	}
	printf("\n");

}

bool equal_array(int counts1[26], int counts2[26]){

	int i;
	
	for(i = 0;i<26;i++){
		if(counts1[i] != counts2[i]){
			//printf("difference found at index %d", i);
			return false;
		}
	}
	return true;	
}


int main(){
	
	int counts1[26] = {0};
	int counts2[26] = {0};
	bool isAnagram;

	//arrays are passed by reference to the functions
	read_word(counts1);
	read_word(counts2);

	isAnagram = equal_array(counts1,counts2);

	if(isAnagram){
		printf("The two entries are anagrams!");
	}
	else
		printf("The two entries not  anagrams!");
		
	printf("\n");

	return 0;
}
