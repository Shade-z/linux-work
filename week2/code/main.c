#include"uhead.h"
int main(){
	int a[NUMBER],b[NUMBER], i;
	struct arg t;
	urand(a, NUMBER);
	usum(a, NUMBER);
	t = uoperator(a, NUMBER);
	printf("sum=%d,ave=%f,max=%d,min=%d\n", t.sum, t.ave,t.max,t.min);
	for(i=0;i<NUMBER;i++){
		b[i] = a[i];
	}
	syssort(a, NUMBER);
	mysort(b, NUMBER);
	for(i=0;i<NUMBER;i++){
		printf("%d ", a[i]);
	}
	writeArrayTo("a.txt", a, sizeof(a)/sizeof(int));
	writeArrayTo("b.txt", b, sizeof(b)/sizeof(int));
	return 0;
}
