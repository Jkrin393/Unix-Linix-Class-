#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int main(){
	
	char word1[50];
	char word2[50];
	
	bool isAnagram = true;
	
	printf("Please enter the first word: ");
	scanf("%s", word1);

	printf("Please enter the second  word: ");
	scanf("%s", word2);
	
	int i;
	int len1,len2;

	//test for same length
	len1 = strlen(word1);
	len2 = strlen(word2);
	

	if(len1 != len2){
		isAnagram = false;
	}
	
	int letter_count[26] = {0};
	//array of 26 to count each letter. If the charachter is alphabetical, change it to lower case, and increment the matching index in letter count by subtracting the ascii value if a.
	for(i=0;i<len1;i++){
		if(isalpha(word1[i])){
			word1[i] = tolower(word1[i]);
			letter_count[word1[i] - 'a']++;
		}
	}
	
	// similar to the first word, but we decrement the count as we see letters
	for(i=0;i<len2;i++){
		if(isalpha(word2[i])){
			word2[i] = tolower(word2[i]);
			letter_count[word2[i] - 'a']--;
		}
	}
	

	for(i=0;i<26;i++){
		if(letter_count[i] !=0){
			isAnagram = false;
			break;
		}
	}

	
	if(isAnagram == true){
		printf("the words are anagrams!");
	}
	else{
		printf("the words are NOT anagrams!");
	}

	return 0;
}
	/*for(i=0;i<len1;i++){
		printf("%c", word1[i]);
	}
	printf("\n");*/
