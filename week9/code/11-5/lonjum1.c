#include"head.h"
#include<setjmp.h>
static jmp_buf g_stack_env;

static void func1(void);
static void func2(void);

int main(){
	if(0 == setjmp(g_stack_env)){
		printf("Normal folw\n");
		func1();
	}else{
		printf("Long jump flow\n");
	}
	return 0;
}
static void func1(void){
	printf("Enter func1\n");
	func2();
}
static void func2(void){
	printf("Enter func2\n");
	longjmp(g_stack_env, 1);
	printf("Leave func2\n");
}
