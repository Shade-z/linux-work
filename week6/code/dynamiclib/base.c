#include<stdio.h>
#include<stdlib.h>
#include"uhead.h"
void show(int * a, int b){
	int i=0;
	if(b<=0){printf("Array's length is below 0\n");exit(1);}
	for(;i<b;i++){
		printf("%4d ", a[i]);
	}
}
void init(int * a, int b){
	int i=1, maxValue;
	if(b<=0){printf("Array's length is below 0\n");exit(1);}
	urand(a, b);
}
