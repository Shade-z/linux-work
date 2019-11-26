#include "head.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main(){
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];
	int fd[2];
	int ret;
	pid_t pid;
	memset(a, 'A', sizeof(a));
	memset(b, 'B', sizeof(b));
	memset(c, 'C', sizeof(c));
	if(pipe(fd) == -1){
		fprintf(stderr, "create pipe error (%s)\n", strerror(errno));
		exit(-1);
	}
	pid = fork();
	if(pid == -1){
		fprintf(stderr, "first fork error (%s)\n", strerror(errno));
		exit(-2);
	}else if(pid == 0){
		close(fd[0]);
		int loop = 0;
		while(loop++<10){
			ret=write(fd[1], a, sizeof(a));//将a数组里面的内容写入管道
			printf("[child] pid=%d write %d bytes to pipe.\n", getpid(), ret);
		}
		exit(0);
	}

	pid = fork();
	if(pid == -1){
		fprintf(stderr, "second fork error (%s)\n", strerror(errno));
		exit(-3);
	}else if(pid == 0){
		close(fd[0]);
		int loop = 0;
		while(loop++<10){
			ret=write(fd[1], b, sizeof(b));//将b数组里面的内容写入管道
			printf("[child] pid=%d write %d bytes to pipe.\n", getpid(), ret);
		}
		exit(0);
	}

	pid = fork();
	if(pid == -1){
		fprintf(stderr, "third fork error (%s)\n", strerror(errno));
		exit(-4);
	}else if(pid == 0){
		close(fd[0]);//关闭读管道
		int loop = 0;
		while(loop++<10){
			ret=write(fd[1], c, sizeof(c));//将c数组里面的内容写入管道
			printf("[child] pid=%d write %d bytes to pipe.\n", getpid(), ret);
		}
		exit(0);
	}
	close(fd[1]);
	sleep(2);
	int fp = open("./test.data", O_WRONLY|O_CREAT|O_TRUNC, 0664);
	char buf[1024*4] = {0};
	int n = 1;
	while(1){
		ret = read(fd[0], buf, sizeof(buf));
		if(ret == 0){//当管道中没有数据可以读取时，就退出循环
			break;
		}
		printf("n=%02d pid=%d read %d bytes from pipe buf[4095]=%c\n", n++, getpid(),ret, buf[4095]);
		write(fp, buf, ret);
	}
}
