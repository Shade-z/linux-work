#include"mylib.h"
int main(){
	int Num = 20, array[Num];
	init(array, Num);
	show(array, Num);
	printf("\nmax=%d\n", max(array, Num));
	printf("min=%d\n", min(array, Num));
	return 0;
}
