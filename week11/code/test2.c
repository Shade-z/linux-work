#include"head.h"
int main(){
	int p = fork();
	if(p<0){
		printf("fork error!\n");
		exit(-1);
	}else if(p == 0){
		printf("child pid:%d,in while!\n", getpid());
		while(1);
		printf("child pid:%d,gona exit!\n", getpid());
		exit(0);
	}else{
		printf("parent pid:%d, is waiting zombie.\n", getpid());
		while(1);
	}
	exit(0);
}
//后台运行./test2&
//运行后去别的控制台输入ps -aux | grep test1
//ps -ef | grep test1
//杀掉进程:kill -9 进程ID
//kill 父进程后，子进程由ID为1的进程接管
