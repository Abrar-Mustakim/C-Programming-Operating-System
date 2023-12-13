
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define TOTAL_TICKETS 10
#define TOTAL_PERSONS 12
int remainingTickets = TOTAL_TICKETS;
sem_t boothSemaphore[2]; 
void *PurchaseTicket(void *personID) {
    int ID = *((int *)personID);
    int boothNumber = ID % 2; 
    sem_wait(&boothSemaphore[boothNumber]); 
    if (remainingTickets > 0) {
        printf("Person %d is purchasing\n", ID);
        printf("Tickets left: %d\n", remainingTickets);
        remainingTickets--;
        printf("Person: %d, Purchase Done\n", ID);
    } else {
        printf("Person %d can not purchase\n", ID);
        printf("Tickets left: 0\n");
        printf("Person: %d, Purchase failed\n", ID);
    }
    sem_post(&boothSemaphore[boothNumber]); 
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[TOTAL_PERSONS];
    int personIDs[TOTAL_PERSONS];
    for (int i = 0; i < 2; i++) {
        sem_init(&boothSemaphore[i], 0, 1); 
    }
    for (int i = 0; i < TOTAL_PERSONS; i++) {
        personIDs[i] = i + 1;
        pthread_create(&threads[i], NULL, PurchaseTicket, &personIDs[i]);
    }
    for (int i = 0; i < TOTAL_PERSONS; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        sem_destroy(&boothSemaphore[i]); 
    }
    return 0;
}




