#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#include <unistd.h>
#include <pthread.h>
#include "messageAdder.h"
#include "msg.h"
#include "iMessageAdder.h"
#include "multitaskingAccumulator.h"
#include "iAcquisitionManager.h"
#include "debug.h"
#include <stdatomic.h>

//consumer thread
pthread_t consumer;
//Message computed
volatile MSG_BLOCK out;
//Consumer count storage
_Atomic int consumeCount = 0;

/**
 * Increments the consume count.
 */
static void incrementConsumeCount(void);

/**
 * Consumer entry point.
 */
static void *sum( void *parameters );


MSG_BLOCK getCurrentSum(){
	//TODO
	return out;
}
// increment consume count
static void incrementConsumeCount(void){
	consumeCount++;
}
unsigned int getConsumedCount(){
	//TODO
	consumeCount = getProducedCount() - consumeCount;
	return consumeCount;
}


void messageAdderInit(void){
	out.checksum = 0;
	for (size_t i = 0; i < DATA_SIZE; i++)
	{
		out.mData[i] = 0;
	}
	//TODO
	printf("Creating the consumer thread\n");
    pthread_create(&consumer, NULL, sum, NULL);

	return; 
}

void messageAdderJoin(void){
	//TODO
	printf("Waiting the consumer thread end\n");
	pthread_join(consumer, NULL);

	return;
}

static void *sum( void *parameters )
{
	D(printf("[messageAdder]Thread created for sum with id %d\n", gettid()));
	unsigned int i = 0;
	while(i<ADDER_LOOP_LIMIT){
		i++;
		sleep(ADDER_SLEEP_TIME);
		//TODO
		MSG_BLOCK msg = getMessage();
		if(messageCheck(&msg)){
			messageAdd(&out, &msg);
			incrementConsumeCount();
		}
	}
	printf("[messageAdder] %d termination\n", gettid());
	//TODO
	pthread_exit(NULL);

}


