#include"uhead.h"
int usum(int a[], int number){
	int i,s;
	for(i=0;i<number;i++){
		s=s+a[i];
	}
	return s;
}

void urand(int a[], int number){
	int i=0;
	srand((int)time(0));
	for(i=0;i<number;i++){
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
}
