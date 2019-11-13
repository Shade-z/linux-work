#include <stdio.h>
#include <unistd.h>
int main(){
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	//system("/home/rlk/linuxprogram/week9/code/11-4");
	char *args[]={"/home/rlk/linuxprogram/week9/code/11-4/test",NULL};
	execve("/home/rlk/linuxprogram/week9/code/11-4/test",args,NULL);
	printf("after calling\n");
	return 0;
}
