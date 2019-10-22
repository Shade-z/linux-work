#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int globa = 4;
int main(){
	pid_t pid;
	int var = 5;
	printf("before fork:\n");
	if((pid = fork()) < 0){
		printf("fork error\n");
		exit(0);
	}else if(pid == 0){
		globa++;
		var--;
		printf("Child changed\n");
		printf("child: globa = %d, var = %d\n", globa, var);
	}else{
		printf("Parent did not changed\n");
		printf("parent: globa = %d, var = %d\n", globa, var);
	}
	return 0;
}
