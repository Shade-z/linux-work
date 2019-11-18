#include"head.h"
int main(){
	int s, s1, s2;
	int p1, p2, p, p11, p22;
	if(((p1 = fork())&&(p2 = fork()))<0){
		printf("p1 fork error!\n");
		exit(-1);
	}else if(p1 == 0){
		printf("p1 child pid:%d,gona exit!\n", getpid());
		exit(110);
	}else if(p2 == 0){
		printf("p2 child pid:%d,gona exit!\n", getpid());
		exit(120);
	}else{
		p11 = wait(&s1);
		p22 = wait(&s2);
		printf("first code:%d  second code:%d\n", WEXITSTATUS(s1), WEXITSTATUS(s2));
		/*if(WEXITSTATUS(s1) == 110){
			printf("child %d 11\n", p11);
		}
		if(WEXITSTATUS(s2) == 120){
			printf("child %d 22\n", p22);
		}*/
		/*while(p=waitpid(p1, &s, WNOHANG)!=-1){
			if(WIFEXITED(s))
				printf("child %d exit normally, exit code = %d\n", p, WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d exit by signal, exit code = %d\n", p, WTERMSIG(s));
			else
				printf("not know\n");
		}*/
		printf("parent pid:%d, is exiting.\n", getpid());
	}
	exit(0);
}
//
