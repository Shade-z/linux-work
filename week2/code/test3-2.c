#include<stdlib.h>
#include"stdio.h"
#include<sys/time.h>
#include<unistd.h>
int compare(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
void main(){
	int i,j,temp=0;
	int a[100],b[100];
	struct timeval tv1,tv2;
	struct timezone tz;
	srand((int)time(0));
	for(i=0;i<100;i++){
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
		b[i]=a[i];
	}
	gettimeofday(&tv1,&tz);
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = b[i];
				b[i] = temp;
			}
		}
	}
	gettimeofday(&tv2,&tz);
	printf("%ld\n",tv2.tv_usec-tv1.tv_usec);
	gettimeofday(&tv1,&tz);
	qsort(&b[0],100,sizeof(int),compare);
	gettimeofday(&tv2,&tz);
	printf("%ld\n",tv2.tv_usec-tv1.tv_usec);
}
