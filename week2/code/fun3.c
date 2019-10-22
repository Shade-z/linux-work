#include"uhead.h"
int compare(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
void syssort(int a[], int number){
	struct timeval tv1,tv2;
	struct timezone tz;
	int i=0;
	gettimeofday(&tv1,&tz);
	qsort(&a[0],100,sizeof(int),compare);
	gettimeofday(&tv2,&tz);
	printf("%ld\n",tv2.tv_usec-tv1.tv_usec);
}
void mysort(int a[], int number){
	struct timeval tv1,tv2;
	struct timezone tz;
	int i=0, j=0, temp=0;
	gettimeofday(&tv1,&tz);
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	gettimeofday(&tv2,&tz);
	printf("%ld\n",tv2.tv_usec-tv1.tv_usec);
}
