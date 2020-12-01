#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


pthread_mutex_t mutx1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutx2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutx3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t msd = PTHREAD_MUTEX_INITIALIZER;


void* first_task(void* args)
{
    int *arg = (int*) args;
   pthread_mutex_lock(&mutx1);
   arg[0]++;
   arg[1]++;
}

void* second_task(void* args)
{
    int *arg = (int*) args;
   pthread_mutex_lock(&mutx1);
   arg[1]++;
   arg[2]++;
}

void* third_task(void* args)
{
    int *arg = (int*) args;
   pthread_mutex_lock(&mutx1);
   arg[2]++;
   arg[0]++;
}

int main(int argc, char **argv)
{
    int a,b,c;   
    a=0;
    b=0;
    c=0;
    pthread_t threads[3];
    int args[3];
    args[0]=a;
    args[1]=b;
    args[2]=c;
    if(pthread_create(&threads[0], NULL, first_task, (void*) &args[3]))
    {
        printf("thread creation error\n");
        return 1;
    }
    if(pthread_create(&threads[1], NULL, second_task, (void*) &args[3]))
    {
        printf("thread creation error\n");
        return 1;
    }
    if(pthread_create(&threads[2], NULL, third_task, (void*) &args[3]))
    {
        printf("thread creation error\n");
        return 1;
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    printf("program finished successfully\n");

    return 0;
}
