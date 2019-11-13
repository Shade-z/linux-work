#include"head.h"
//在1-7.c的基础上改的
int g = 10;
int main(){
	int s =20;
	static int k = 30;
	pid_t pid;
	pid = vfork();
	if(pid < 0){
		perror("vfork failed!\n");
		return -1;
	}else if(pid == 0){//子进程
        sleep(2);
        execl("./test","test",NULL);
        static long h=100;
		printf("child pid=%d &g=%16p\n&k=%16p\n&s=%16p\n&h=%16p\n", getpid(), &g, &k, &s, &h);
		g = 100;
		s = 200;
		k = 300;
		printf("child after g=%d, s=%d, k=%d, h=%ld\n", g, s, k, h);
		sleep(2);
		_exit(0);//可以正常退出
		//return 0;//会报错
	}else{
		printf("parent pid=%d &g=%16p\n&k=%16p&s=%16p\n", getpid(), &g, &k, &s);
		printf("parent pid = %d :g=%d,k=%d,s=%d\n",getpid(),g,k,s);
		return 0;
	}
}
