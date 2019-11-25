#include"head.h"
int main(){
	pid_t r1, r2, r3;
	int r_num;
	int pipefd1[2], pipefd2[2];
	char buf[4097];//32位机器才是4096字节大小
	char buf2[4097];
	memset(buf, 0, sizeof(buf));
	memset(buf2, 97, sizeof(buf2));
	if(pipe(pipefd1)<0 || pipe(pipefd2)<0){
		perror("pipe failed!\n");
		return -1;
	}
	r1 = fork();
	if(r1<0){
		perror("fork1 failed!\n");
		return -1;
	}else if(r1==0){
		close(pipefd1[0]);
		if(write(pipefd1[1], buf2, 4097)!=-1){
			printf("child1 write\n");
		}
		close(pipefd1[1]);
		exit(0);
	}else{
		r2 = fork();
		if(r2<0){
			perror("fork2 failed!\n");
			return -1;
		}else if(r2==0){
			close(pipefd1[1]);
			if(r_num=read(pipefd1[0], buf, 4097)>0){
				printf("child2 read from pipe: %s, size=%ld,total=%d\n", buf, sizeof(buf), r_num);
			}
			close(pipefd1[0]);

			
			close(pipefd2[0]);
			if(write(pipefd2[1], buf, 4097)!=-1){
				printf("child2 write\n");
			}
			close(pipefd2[1]);
			exit(0);
		}else{
			r3 = fork();
			if(r3<0){
				perror("fork3 failed!\n");
				return -1;
			}else if(r3==0){
				close(pipefd2[1]);
				if(r_num=read(pipefd2[0], buf, 4097)>0){
					printf("child3 read from pipe: %s, size=%ld,total=%d\n", buf, sizeof(buf), r_num);
				}
				close(pipefd2[0]);
				exit(0);
			}else{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				return 0;
			}
		}
	}
}
