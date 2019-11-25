#include"head.h"
int main(){
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4097];//32位机器才是4096字节大小
	char buf2[4097];
	memset(buf, 0, sizeof(buf));
	memset(buf2, 97, sizeof(buf2));
	if(pipe(pipefd)<0){
		perror("pipe failed!\n");
		return -1;
	}
	r = fork();
	if(r<0){
		perror("fork failed!\n");
		return -1;
	}else if(r==0){
		close(pipefd[1]);
		if(r_num=read(pipefd[0], buf, 4097)>0){
			printf("child read from pipe: %s, size=%d,total=%d\n", buf, sizeof(buf), r_num);
		}
		close(pipefd[0]);
		exit(0);
	}else{
		close(pipefd[0]);
		if(write(pipefd[1], buf2, 4097)!=-1){
			printf("parent write\n");
		}
		close(pipefd[1]);
		return 0;
	}
	return 0;
}
