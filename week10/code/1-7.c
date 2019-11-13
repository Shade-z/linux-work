#include"head.h"
int g = 10;
int main(){
	int s =20;
	static int k = 30;
	pid_t pid;
	pid = vfork();//这里更改成了vfork
	if(pid < 0){
		perror("vfork failed!\n");
		return -1;
	}else if(pid == 0){//子进程
		printf("child pid=%d &g=%16p\n&k=%16p&s=%16p\n", getpid(), &g, &k, &s);
		g = 100;
		s = 200;
		k = 300;
		sleep(2);
		printf("child after g=%d, s=%d, k=%d\n", g, s, k);
        //while(g!=400)
        //	printf("%d:waiting for g=400!\n",getpid());//会产生僵尸进程
		_exit(0);//可以正常退出
		//return 0;//会报错
	}else{
		//g=400;
		printf("parent pid=%d &g=%16p\n&k=%16p&s=%16p\n", getpid(), &g, &k, &s);
		printf("parent after g=%d, s=%d, k=%d\n", g, s, k);
		return 0;
	}
}
