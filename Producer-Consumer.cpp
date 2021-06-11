#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
#define MaxItems 5
#define buffer_size 5

int Size;
int buffer[buffer_size];
int index=0;

sem_t full,empty_;
pthread_mutex_t mutex;



void* produce(void* arg){
	for(int i = 0; i<MaxItems;i++){
		this_thread::sleep_for(chrono::milliseconds((rand()%100)+1) );
		sem_wait(&empty_); // wait/sleep when there are no empty slots
		pthread_mutex_lock(&mutex);
		int item = rand()%100;
		buffer[index++] = item;
		cout<<"Produced "<<item << endl;
		cout<<"Empty Space: " << Size - index<<endl;
		cout<<"Full Space: " << index <<endl;
		pthread_mutex_unlock(&mutex);
		sem_post(&full); // Signal/wake to consumer that buffer has some   data and they can consume now
	}
}

void* consume(void* arg){
	for(int i = 0; i<MaxItems;i++){
		this_thread::sleep_for(chrono::milliseconds((rand()%100)+1) );
		sem_wait(&full);  // wait/sleep when there are no full slots
		pthread_mutex_lock(&mutex);
		int item = buffer[--index];
		cout<<"Consumed "<<item<<endl;
		cout<<"Empty Space: " << Size - index <<endl;
		cout<< "Full Space: " << index << endl;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty_);  // Signal/wake the producer that buffer slots are emptied and they can produce more
	}
}

int main(){
    cout<<"Enter the size of the buffer: "<<endl;
    cin>>Size;
	pthread_t producer,consumer;
	sem_init(&empty_,0,Size);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&producer,NULL,produce,NULL);
	pthread_create(&consumer,NULL,consume,NULL);
	pthread_exit(NULL);
	return 0;
}
