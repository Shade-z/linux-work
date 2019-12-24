#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 2
#define TCOUNT 10
#define COUNT_LIMIT 5

int count = 0;
int thread_ids[3] = {0,1,2};
char words[] = {'l','i','n','u','x','g'};
pthread_mutex_t count_mutex;
pthread_cond_t count_threadhold_cv;

void *watch_count(void *idp){
    int *my_id = idp;
    printf("Staring watch count(): thread %d\n",*my_id);
    pthread_mutex_lock(&count_mutex);
    if (count<COUNT_LIMIT)
    {
        pthread_cond_wait(&count_threadhold_cv, &count_mutex);
        printf("watch_count():thread %d condition signal received.\n",*my_id);
    }
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}
void *inc_count(void *idp){
    int j,i;
    double result=0.0;
    int *my_id = idp;
    for ( i = 0; i < TCOUNT; i++)
    {
        pthread_mutex_lock(&count_mutex);
        count++;
        if (count==COUNT_LIMIT)
        {
            pthread_cond_signal(&count_threadhold_cv);
            printf("inc_count():thread %d,count = %d Threshold reached.\n",*my_id,count);
        }
        printf("inc_count():thread %d,count = %d unlocking mutex.\n",*my_id,count);
        pthread_mutex_unlock(&count_mutex);
        for ( j = 0; j < 1000; j++)
        {
            result = result + (double)random();
        }
        pthread_exit(NULL);
    }
}
void *count_words(void *f){
    char *filename=(char *)f;
    FILE *fp;
    int c,prevc='\0';
    int total_words=0;
 
    if((fp=fopen(filename,"r"))!=NULL){
        while((c=getc(fp))!=EOF)
        {
        if(!isalnum(c) && isalnum(prevc)){
            pthread_mutex_lock(&count_mutex);
            total_words++;
            pthread_mutex_unlock(&count_mutex);
        } 
        prevc=c;
        }
        fclose(fp);
        printf("total_words=%d\n",total_words);
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    int i,rc;
    int total_words=0;

    pthread_t threads[2];
    pthread_attr_t attr;
    pthread_mutex_init(&count_mutex,NULL);
    pthread_cond_init(&count_threadhold_cv,NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[0],&attr,inc_count,(void *)&thread_ids[0]);
    pthread_create(&threads[1],&attr,watch_count,(void *)&thread_ids[1]);
    // pthread_create(&threads[2],&attr,watch_count,(void *)&thread_ids[2]);
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i],NULL);
    }
    printf("Main():Waited on %d threads. Done.\n",NUM_THREADS);

    printf("total_words=%d\n",total_words);
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threadhold_cv);
    pthread_exit(NULL);
    
}
int main1(int argc, char const *argv[]){

    void *count_words(void *);
    if(argc!=3)
    {
        printf("Usage:%s file1 file2\n",argv[0]);
        exit(1);
    }
    pthread_t tidp1,tidp2;
    int error1,error2;
    error1=pthread_create(&tidp1,NULL,count_words,argv[1]);
    error2=pthread_create(&tidp2,NULL,count_words,argv[2]);
    pthread_join(tidp1,NULL);
    pthread_join(tidp2,NULL);
}
