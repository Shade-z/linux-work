#include"head.h"
int main(){
	int ret;
	char *arg[]={"./test2","123","abc","hello","ncu","edu",NULL};
	printf("call1:pid=%d,ppid=%d", getpid(), getppid());
	ret = execvp("test2", arg);
	printf("after calling ret=%d", ret);
	return 0;
}
