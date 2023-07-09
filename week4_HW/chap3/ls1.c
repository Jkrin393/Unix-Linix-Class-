/*chap 3, program problem 3.11, page 105*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls(const char []);

int main(int ac, char *av[]){
	int i;
	
	if(ac==1){
		printf("ac = 1 \n");
	}
	else{
		for(i=1;i<ac; i++)
		{
		//	printf("%s:\n", av[i]);
			do_ls(av[i]);
		//	printf("\n");
		}
	}
	return 0;
}//end main

void do_ls(const char dirname[]){
	//list files in directory <dirname>
	DIR *dir_ptr; /*the directory*/
	struct dirent *direntp; //each entry. dirent has d_name, d_type, d_reclen
	
	if((dir_ptr = opendir(dirname))==NULL){
		fprintf(stderr, "ls1: cannot open %s\n", dirname);
		return;
	}
	
	while(( direntp=readdir(dir_ptr))!=NULL){
		if((direntp -> d_name[0])== '.'){
			continue;
		}
		printf("%s\t", direntp->d_name);
	}
	printf("\n");
	closedir(dir_ptr);
	
	
}
