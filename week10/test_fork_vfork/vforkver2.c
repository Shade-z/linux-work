#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	pid_t pid;
	FILE* fp;
	int file;
	int i = 0, j = 0;
	char buf1[]={"child:0\n"};
	char buf2[]={"parent:0\n"};
	if((file=open("test.data", O_RDWR|O_CREAT))<0){
		perror("failed to open!\n");
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
			if(write(file, buf1 , sizeof(buf1)) == -1){
				perror("child:failed to puts!\n");
				return -1;
			}
		}
		return 0;
	}else{
		printf("parent:pid=%d,writing file\n", getpid());
		if(file > 0){//printf("flags:%u\n", fp->_flags);
			for(j=0;j<10;j++){
				//printf("file:%p  buf2:%p %s\n", fp, buf2, buf2);
				strcpy(buf2, "parent: \n\0");buf2[7] = j+48;
				if(write(file, buf2 , sizeof(buf2)) == -1){
					perror("parent:failed to puts!\n");
					return -1;
				}
			}
		}else{printf("file is null!\n");}
	}
	close(file);
	return 0;
}
