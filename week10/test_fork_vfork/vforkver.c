#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	pid_t pid;
	FILE* fp;
	int i = 0, j = 0;
	char buf1[]={"child:0\n"};
	char buf2[10]={"parent:0\n"};
	if((fp=fopen("test.data", "w+"))==NULL){
		perror("failed to fopen!\n");
		return -1;
	}
	pid = vfork();
	if(pid<0){
		perror("fork failed\n");
		exit(-1);
	}else if(pid == 0){
		printf("child:pid=%d,writing file\n", getpid());
		for(i=0;i<10;i++){
			buf1[6] = i+48;
			if(fputs(buf1 , fp) == EOF){
				perror("child:failed to fputs!\n");
				return -1;
			}
		}
		return 0;
	}else{
		printf("parent:pid=%d,writing file\n", getpid());
		for(j=0;j<10;j++){
			//printf("file:%p  buf2:%p %s\n", fp, buf2, buf2);
			strcpy(buf2, "parent: \n\0");buf2[7] = j+48;
			if(fputs(buf2, fp) == EOF){
				perror("parent:failed to fputs!\n");
				return -1;
			}
		}
	}
	fclose(fp);
	return 0;
}
