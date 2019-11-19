#include"head.h"
int main(){
	int s1, s2;
	FILE *fp;
	int p1, p2, p11, p22;
	int i,j;
	if((fp=fopen("out.data", "w+"))==NULL){
		perror("failed to fopen!\n");
		return -1;
	}
	if(((p1 = fork())&&(p2 = fork()))<0){
		printf("fork error!\n");
		exit(-1);
	}else if(p1 == 0){
		printf("child p1:pid=%d,writing file\n", getpid());
		for(i=0;i<10;i++){
			fprintf(fp,"p1 pid=%d:%d\n", getpid(), i);
		}
		return 0;
	}else if(p2 == 0){
		printf("child p2:pid=%d,writing file\n", getpid());
		for(j=0;j<10;j++){
			fprintf(fp,"p2 pid=%d:%d\n", getpid(), j);
		}
		return 0;
	}else{
		p11 = wait(&s1);
		p22 = wait(&s2);
		printf("first code:%d p11=%d  second code:%d  p22=%d\n", WEXITSTATUS(s1), p11, WEXITSTATUS(s2), p22);
		printf("parent pid:%d, is exiting.\n", getpid());
	}
	exit(0);
}
