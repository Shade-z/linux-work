#include"head.h"
int i=0;
//这里的foo总共会循环7934次，函数的堆栈空间共有8M
void foo(){
	int buffer[256]={0};
	i += 1;
	printf("i=%d\n", i);
	foo();
}
void main(){
	foo();
}
