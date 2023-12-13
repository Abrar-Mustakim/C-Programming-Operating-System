//20301125
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'};   //indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; ////initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *farmer_number)
{
    int farmer_num = *(int *)farmer_number;

    while (1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

       
        printf("Farmer %d: Insert crops %c at %d\n", farmer_num, crops[farmer_num - 1], in);
        warehouse[in] = crops[farmer_num - 1];
        in = (in + 1) % warehouseSize;
        printf("Farmer%d: %c%c%c%c%c\n", farmer_num, warehouse[0], warehouse[1], warehouse[2], warehouse[3], warehouse[4]);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *ShopOwner(void *shopowner_number)
{
    /*
    1.Shop owner takes crops and makes that particular room empty.
    2.use mutex and semaphore for critical section.
    3.print which shop owner is taking which crops from which room inside the
    critical section.
    4.print the whole warehouse buffer outside of the critical section
    */

    int shopowner_num = *(int *)shopowner_number;

    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Shop owner %d: Remove crops %c from %d\n", shopowner_num, warehouse[out], out);
        warehouse[out] = 'N';
        out = (out + 1) % warehouseSize;
        printf("ShopOwner%d: %c%c%c%c%c\n", shopowner_num, warehouse[0], warehouse[1], warehouse[2], warehouse[3], warehouse[4]);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    /*initializing thread,mutex,semaphore
    */
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);//the warehouse is full thread will wait
    sem_init(&full, 0, 0);//the warehouse is empty thread will wait
    int a[5] = {1, 2, 3, 4, 5}; ////Just used for numbering the Farmer and ShopOwner
    /*create 5 thread for Farmer 5 thread for ShopOwner
    -------------------------------------------------
    -------------------------------------------------
    */
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&Far[i], NULL, Farmer, (void *)&a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, (void *)&a[i]);
    }
    sleep(10);
    // Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
