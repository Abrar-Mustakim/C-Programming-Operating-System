#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define NUM_THREADS 5
#define NUM_INTEGERS 5

void *threadFunction(void *arg) {
    int thread_num = *((int *)arg);

    for (int i = 1; i <= NUM_INTEGERS; ++i) {
        printf("Thread %d prints %d\n", thread_num, (thread_num * NUM_INTEGERS) + i);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]);
        pthread_join(threads[i], NULL);
    }

    return 0;
}
