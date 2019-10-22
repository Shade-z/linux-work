#include<sys/types.h>
#include<fcntl.h>
#include"myhead.h"
int main(int argc, char *argv[]){
	int accmode, val;
	if(argc != 2){
		perror("usage: a.out <descriptor#>");
		return 1;
	}
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
		printf("ffcntl error for fd %d", atoi(argv[1]));
		return 1;
	}
	accmode = val & O_ACCMODE;
	if(accmode == O_RDONLY) printf("read only");
	else if(accmode == O_WRONLY) printf("write only");
	else if(accmode == O_RDWR) printf("READ write");
	else printf("unknown access mode");
	if(val & O_APPEND)  printf(",append");
	if(val & O_NONBLOCK)  printf(",nonblocking");
	#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
		if(val & O_SYNC)  printf(", synchronous writes");
	#endif
	putchar('\n');
	return 0;
}
