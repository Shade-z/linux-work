#include"stdio.h"
#include"math.h"
int main(){
	int n,t,m;
	float a=2,b=1,s=0;
	scanf("%d",&m);
	for(n=1;n<=m;n++){
		s=s+(a/b)*pow(-1,n+1);
		t = a;
		a = a+b;
		b=t;
	}
	printf("sum is %9.6f\n",s);
	return 0;
}
