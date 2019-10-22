#include<stdio.h>
int main(int argc, char *argv[]){
	printf("hello");
	//while(1);

	//printf("hello\n");
	
	//for(int i=0;i<204;i++)printf("hello");
	//while(1);

	//fclose(stdout);

	setvbuf(stdout, NULL, _IONBF, 0);
	while(1);
}
