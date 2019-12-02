#include"head.h"
void catchSignal(int dunno){
	switch(dunno){
		case 1:
			printf("Get a signal SIGHUP\n");//终端发送信号
			break;
		case 2:
			printf("Get a signal SIGINT\n");//通过Ctrl+C触发
			break;
		case 3:
			printf("Get a signal SIGQUIT\n");//ctrl+\
			break;
	}
}
int main(){
	printf("process id is %d\n", getpid());
	signal(SIGHUP, catchSignal);//将各个信号与catchSignal函数绑定
	signal(SIGINT, catchSignal);//即产生这些信号时，会由catchSignal捕捉然后进行处理，因此默认处理的会失效
	signal(SIGQUIT, catchSignal);
	while(1);
	return 0;
}
