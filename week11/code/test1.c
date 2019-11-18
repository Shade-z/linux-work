#include"head.h"
int main(){
	int p = fork();
	if(p<0){
		printf("fork error!\n");
		exit(-1);
	}else if(p == 0){
		printf("child pid:%d,gona exit!", getpid());
	}else{
		printf("parent pid:%d, in while", getpid());
		while(1);
	}
	exit(0);
}

//运行后去别的控制台输入ps -aux | grep test1
//杀掉进程:kill -9 进程ID
