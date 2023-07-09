#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>


//function to move file
void move_file(const char* old_path, char* new_path);

//function to detect if second argument is a directory

int main(int av, char* args[]){

	const char* old = args[1];
	char* newf = args[2];

	if(av !=3){
		printf("not enough arguments\n");
		exit(1);
	}

	move_file(old, newf);
	return 0;		
}

void move_file(const char* old_path, char* new_path){
	

	//if destination is a directory
	struct stat stat_path;

	if((stat(new_path, &stat_path) == 0) &&( S_ISDIR(stat_path.st_mode) !=0)){//check if the path exists & is valid by calling stat. Checks if it is a directory with S_ISDIR from stat.h. non-zero when directory 
		
		
		//create new file path
		size_t old_len = strlen(old_path);
		size_t new_len = strlen(new_path);
	//	printf("dir len: %ld, path_len: %ld", old_len, new_len); 

		char* new_dir_path = malloc(old_len + new_len + 2); 

		if(new_dir_path == NULL){
			printf("no memory available");
			exit(1);
		}

		strcpy(new_dir_path, new_path);
		strcat(new_dir_path, "/");
		strcat(new_dir_path, old_path);

		//create new link
		if(link(old_path, new_dir_path) == -1){
			perror("Error creating new link");
			free(new_dir_path);
			exit(1);
		}
		
		//remove the link from the old_path
		if(unlink(old_path)==-1){
			perror("Error deleting old link");
			free(new_dir_path);
			exit(1);
		}


		printf("File moved to new directory: %s\n", new_dir_path);
		free(new_dir_path);
		
	}else{// destination is a file, create a link with the new file name, break the link with the old one
		
		//create new link
		if(link(old_path, new_path) == -1){
			perror("Error creating new file name");
			free(new_path);
			exit(1);
		}
		
		//remove the link from the old_path
		if(unlink(old_path)==-1){
			perror("Error deleting old name");
			free(new_path);
			exit(1);
		}
		
		printf("File renamed to: %s\n", new_path);
		
	
	}

}


