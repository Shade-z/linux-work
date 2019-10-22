#include<stdio.h>
#include<stdlib.h>
int max(int * a, int b){
	int i=1, maxValue;
	if(b<=0){printf("Array's length is below 0\n");exit(1);}
	maxValue= a[0];
	for(;i<b;i++){
		if(maxValue<a[i]) maxValue = a[i];
	}
	return maxValue;
}
int min(int * a, int b){
	int i=1, minValue;
	if(b<=0){printf("Array's length is below 0\n");exit(1);}
	minValue= a[0];
	for(;i<b;i++){
		if(minValue>a[i]) minValue = a[i];
	}
	return minValue;
}
