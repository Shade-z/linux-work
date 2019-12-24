#include "myhead.h"
FILE *file;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
void *fun1(void *n){
	int start=(int)n;
  
	time_t t;
	for(int i=start;i<=start+1000;i++){
		pthread_mutex_lock(&mutex1);
		int rand_num = (int)(1000.0*rand()/(RAND_MAX+1.0));//获取0-999之间的随机数
		if(fprintf(file,"worker1:\t%d\t, time:\t%s", rand_num, asctime(localtime(&t)))<0){
			perror("WRITE ERROR");
			return (void *)-1;
		}
		pthread_mutex_unlock(&mutex2);
		pthread_yield();
	}

	return (void *)0;
}
void *fun2(void *n){
	int start=(int)n;
  
	time_t t;
	for(int i=start;i<=start+1000;i++){
		pthread_mutex_lock(&mutex2);
		int rand_num = (int)(1000.0*rand()/(RAND_MAX+1.0)+1000);//获取1000-1999之间的随机数
		if(fprintf(file,"worker2:\t%d\t, time:\t%s", rand_num, asctime(localtime(&t)))<0){
			perror("WRITE ERROR");
			return (void *)-1;
		}
		pthread_mutex_unlock(&mutex1);
		pthread_yield();
	}

	return (void *)0;
}
void *fun3(void *n){
	char temp[256];
	fseek(file, 0, SEEK_SET);
	while(fread(temp, 1, 256, file)>0){
		printf("%s", temp);
	}
	return (void *)0;
}


void *master(void *n){
   pthread_t tid[3];
   int ret[3],i;

       ret[0]=pthread_create(&tid[0],NULL, fun1,(void*)1);
       if(ret[0] != 0){
             perror("failed!\n");
             return (void *)-1;
         }

       ret[1]=pthread_create(&tid[1],NULL, fun2,(void*)1001);
       if(ret[1] != 0){
             perror("failed!\n");
             return (void *)-1;
         }

		//写文件
       pthread_join(tid[0],NULL);
       pthread_join(tid[1],NULL);

		//读文件
       ret[2]=pthread_create(&tid[2],NULL, fun3,NULL);
       if(ret[2] != 0){
             perror("failed!\n");
             return (void *)-1;
        }
       pthread_join(tid[2],NULL);
   
   pthread_exit(NULL);
   return (void *)0;
}



int main(){
   pthread_t tid;
   int ret;

   if((file=fopen("mydate.txt","w+"))==NULL){
		perror("ERROR OPEN FILE2");
		return -1;
	}

	pthread_mutex_init(&mutex1,NULL);
	pthread_mutex_init(&mutex2,NULL);

   ret=pthread_create(&tid,NULL,master,NULL);
   if(ret != 0){
         perror("failed!\n");
         return -1;
     }
   pthread_join(tid,NULL);

   fclose(file);
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
   return 0;
}

/*
设计一个master主线程
三个子线程work1、2、3
三个线程共享一个文件 mydate.txt
由master建立

work1和work2 负责写入文件（写一百万字）
Worker1负责写一到一千的整数
Worker2写1001到2000的数
随机数

Worker1：。。。 time：。。。

Worker3：读出

数据 buffer 交替写入

或是用堆写 不用文件malloc
*/


