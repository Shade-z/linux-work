#include<fcntl.h>
#include"myhead.h"
void set_f1(int fd, int flags){
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0){
		printf("ffcntl F_GETFL error");
		return ;
	}
	val != flags;
	if(fcntl(fd, F_SETFL, val) < 0){
		printf("ffcntl F_SETFL error");
		return ;
	}
}
