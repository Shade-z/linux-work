#include"head.h"
// 将捕捉到的信号打印出来
void sighandler(int signo){
	printf("[parent] catch a SIGPIPE signal and signum=%d\n", signo);
}
int main(){
	int fd[2];
	pid_t pid;
	if(signal(SIGPIPE, sighandler)==SIG_ERR){//将SIGPIPE信号和sighandler函数绑定
		fprintf(stderr, "signal error (%s)\n", strerror(errno));
		exit(-1);
	}
	if(pipe(fd) == -1){
		fprintf(stderr, "create pipe error (%s)\n", strerror(errno));
		exit(-2);
	}
	pid = fork();
	if(pid == -1){
		fprintf(stderr, "fork error (%s)\n", strerror(errno));
		exit(-3);
	}else if(pid == 0){
		fprintf(stdout, "[child] i will close the last read ebd of pipe.\n");
		close(fd[0]);//关闭读管道
		exit(0);
	}else{
		close(fd[0]);//关闭读管道
		sleep(1);
		int ret = write(fd[1], "test", 4);
		if(ret == -1){
			fprintf(stderr, "[parent] write error (%s).\n", strerror(errno));
		}
		return 0;
	}
}
