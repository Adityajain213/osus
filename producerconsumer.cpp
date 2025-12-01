#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
#include <unistd.h>
using namespace std;

queue<int> buffer;
int BUFFER_SIZE;

sem_t mutexlock;
sem_t emptyslots;
sem_t fullslots;

void* producer(void* arg)
{
    int item = 0;
    while (true)
    {
        item++;

        sem_wait(&emptyslots);
        sem_wait(&mutexlock);

        buffer.push(item);
        cout << "Producer produced: " << item << endl;

        sem_post(&mutexlock);
        sem_post(&fullslots);

        sleep(1);
    }
}

void* consumer(void* arg)
{
    while (true)
    {
        sem_wait(&fullslots);
        sem_wait(&mutexlock);

        int item = buffer.front();
        buffer.pop();
        cout << "Consumer consumed: " << item << endl;

        sem_post(&mutexlock);
        sem_post(&emptyslots);

        sleep(2);
    }
}

int main()
{
    cout << "Enter size of buffer: ";
    cin >> BUFFER_SIZE;

    pthread_t prod, cons;

    sem_init(&mutexlock, 0, 1);
    sem_init(&emptyslots, 0, BUFFER_SIZE);
    sem_init(&fullslots, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
