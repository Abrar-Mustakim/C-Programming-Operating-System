
//20301125
// Threading Task 1

//gcc -o task1 task1.c -lpthread

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunction(void *arg) {
    int thread_num = *((int *)arg);

    printf("thread-%d running\n", thread_num);
    printf("thread-%d closed\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]);

        pthread_join(threads[i], NULL);
    }

    return 0;
}
