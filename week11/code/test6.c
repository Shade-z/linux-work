#include"head.h"
#include<time.h>
void init_daemon(void){//守护进程初始化函数
	pid_t child1, child2;
	int i;
	child1 = fork();
	if(child1>0){exit(0);}//创建子进程，终结父进程，子进程后台运行
	else if(child1<0){perror("创建子进程失败");exit(1);}
	setsid();	//在子进程中创建新会话
	chdir("./");//更改工作目录到当前目录
	umask(0);//重设文件创建掩码
	for(i=0;i<NOFILE;i++)close(i);//关闭文件描述符
	return;
}
int main(){
	FILE *fp;
	time_t t;
	init_daemon();
	while(1){//无限循环，每10s向文件写入运行状态
		sleep(10);
		if((fp = fopen("6-8.log", "a"))>=0){
			t = time(0);
			fprintf(fp, "守护进程还在运行，时间是:%s",asctime(localtime(&t)));
			fclose(fp);
		}
	}
}
