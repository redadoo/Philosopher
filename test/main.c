# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>


int mails = 0;
int lock = 0;
pthread_mutex_t mymutex;  

void *routine(){
    for (size_t i = 0; i < 1000000; i++)
    {
        if (lock == 1){

        }
        lock = 1;
        mails++;
        lock = 0;
    }
}

int main(void)
{
    pthread_t p1,p2;
}