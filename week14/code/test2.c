#include"head.h"
int i=0;
void foo(){
	int *buffer=malloc(256);;
	i += 1;
	printf("i=%d\n", i);
	foo();
}
void main(){
	foo();
}
