#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


//function to move file
void move_file(const char* old_path, char* new_path);

//function to detect if second argument is a directory
int is_directory(char* argument);


int main(int av, char* args[]){

	const char* old = args[1];
	char* new = args[2];

	if(av <3){
		printf("not enough arguments\n");
		exit(1);
	}

	if(old==NULL || new == NULL){
		printf("invalid file path\n");
		exit(1);
	}
	

	move_file(old, new);
		
}

void move_file(const char* old_path, char* new_path){
	
	
	if(is_directory(new_path) == 0){//second argument is a file
		printf("entered if block of move_file\n");	
		rename(old_path, new_path);
	}
	else{   //destination is a directory "mv test.txt /data_files/etc"
		//create new path location with old_path's name
		printf("entered else block\n");	
		char* new_dir_filename;
		new_dir_filename = strrchr(new_path, '/');	//strrchr returns a pointer to the last instance of the character
		printf("New Name: %s\n", new_dir_filename);	
		char new_dir_name[(strlen(new_path) + strlen(new_dir_filename))+2]; // +2 to allow for backslash &  null pointer
		
		strcpy(new_dir_name, new_dir_filename);
		strcat(new_dir_name, "/");
		strcat(new_dir_name, old_path);

		printf("%s\n", new_dir_name);
	
		if(rename(old_path, new_dir_name) !=0){
			printf("Error renaming file\n");
		}
	}

}


int is_directory(char* argument){
	struct stat stat_path;

	//checks with stat if the path is a directory. Error will occur if it is a file
	if(stat(argument, &stat_path) != 0){
		return 1;// 0 here used to represent false
	}
	return 0;
}
