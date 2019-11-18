#include"head.h"
int main(){
	int s;
	int p = fork();
	if(p<0){
		printf("fork error!\n");
		exit(-1);
	}else if(p == 0){
		
		printf("child pid:%d,gona exit!\n", getpid());
		while(1);//这句是后来加的,运行后杀掉子进程,是exit by signal
		exit(110);//运行后child是exit normally
	}else{
		printf("parent pid:%d, is exiting.\n", getpid());
		while(p=wait(&s)!=-1){
			if(WIFEXITED(s))
				printf("child %d exit normally, exit code = %d\n", p, WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d exit by signal, exit code = %d\n", p, WTERMSIG(s));
			else
				printf("not know\n");
		}
	}
	exit(0);
}
//后台运行./test3&
//运行后去别的控制台输入ps -aux | grep test1
//杀掉进程:kill -9 进程ID
