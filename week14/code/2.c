#include"head.h"
#define NUM_THREADS 4
char msg[20];//这里必须是全局变量才能通过pthread_exit传出数据，或者在join时传入某个变量的地址，然后在处理后pthread_exit传回去
void* hello(void *t){
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i=1;i<=y->n;i++)
		s+=i;
	my_tid=pthread_self();
	printf("\tthread %d, my tid=%lx, Hello\n", (int)y->no, my_tid);
	printf("\tthread %d: sum 1 to %d is %d\n", (int)y->no, y->n, s);
	sprintf(msg, "this is thread %d", y->no);
	printf("\tsending msg:%s\n", msg);
	pthread_exit(msg);//(void *)
}
int main(){
	pthread_t tid;
	int rv, t;
	char *msg;
	struct info a[4];
	for(t=0; t<NUM_THREADS; t++){
		a[t].no = t;
		a[t].n = 100*(t+1);
		gettimeofday(&a[t].start,NULL);
		rv = pthread_create(&tid, NULL, (void *(*)())hello, (void*)&a[t]);
		if(rv != 0){
			printf("thread create failed\n");
			return -1;
		}
		printf("thread create %lx\n", tid);
		pthread_join(tid, &msg);//(void **)
		gettimeofday(&a[t].end,NULL);
		printf("\tthread %d: use_time=%ld, return_value=%s\n", t, a[t].end.tv_usec-a[t].start.tv_usec, msg);
	}
	printf("BYE\n");
	//pthread_exit(NULL);
	return 0;
}
