#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
int thread_ids[3] = {0,1,2};
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