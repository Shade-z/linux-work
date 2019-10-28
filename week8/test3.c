//4.调用getenv/putenv
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%s\n",getenv("PATH"));
	return 0;
}
