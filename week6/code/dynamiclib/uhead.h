#include<stdio.h>
#include"math.h"
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include <fcntl.h>

#define NUMBER 100

struct arg{
	float ave;
	int sum;
	int max;
	int min;
};

int usum(int a[], int number);
void urand(int a[], int number);
struct arg uoperator(int *a, int n);

int compare(const void *a,const void *b);
void syssort(int a[], int number);
void mysort(int a[], int number);

void writeArrayTo(const char* pathName, int *array, int length);
