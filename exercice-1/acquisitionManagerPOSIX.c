#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include "acquisitionManager.h"
#include "msg.h"
#include "iSensor.h"
#include "multitaskingAccumulator.h"
#include "iAcquisitionManager.h"
#include "debug.h"

#include <stdatomic.h> // for atomic variable 
#define SEM_NAME "/acquisitionManager_sem"
#define SEMAPHORE_INITIAL_VALUE 0
volatile MSG_BLOCK msg_bloc; // define a message 
//producer count storage
_Atomic int produceCount = 0; // replace volatile with atomic for more thread safe operation

pthread_t producers[4];

static void *produce(void *params);

/**
* Semaphores and Mutex
*/
//TODO
sem_t *semAcquisition ;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
/*
* Creates the synchronization elements.
* @return ERROR_SUCCESS if the init is ok, ERROR_INIT otherwise
*/
static unsigned int createSynchronizationObjects(void);

/*
* Increments the produce count.
*/
static void incrementProducedCount(void);

static unsigned int createSynchronizationObjects(void)
{

	//TODO
	sem_unlink(SEM_NAME);
    semAcquisition = sem_open(SEM_NAME, O_CREAT, 0644, SEMAPHORE_INITIAL_VALUE);
	if (semAcquisition == SEM_FAILED){
        perror("sem_open");
        return ERROR_INIT;
    }
	printf("[acquisitionManager]Semaphore created\n");
	return ERROR_SUCCESS;
}

static void incrementProducedCount(void)
{
	//TODO
	produceCount++; // incrementation 
}

unsigned int getProducedCount(void)
{
	unsigned int p = 0;
	//TODO
	p = produceCount;
	return p;
}

MSG_BLOCK getMessage(void){
	//TODO
	return msg_bloc;
}

//TODO create accessors to limit semaphore and mutex usage outside of this C module.

unsigned int acquisitionManagerInit(void)
{
	unsigned int i;
	printf("[acquisitionManager]Synchronization initialization in progress...\n");
	fflush( stdout );
	if (createSynchronizationObjects() == ERROR_INIT)
		return ERROR_INIT;
	
	printf("[acquisitionManager]Synchronization initialization done.\n");

	for (i = 0; i < PRODUCER_COUNT; i++)
	{
		//TODO
		printf("Creating the thread\n");
    	pthread_create(&producers[i], NULL, produce, NULL);

	}

	return ERROR_SUCCESS;
}

void acquisitionManagerJoin(void)
{
	unsigned int i;
	for (i = 0; i < PRODUCER_COUNT; i++)
	{
		//TODO
		printf("Waiting the thread end\n");
		pthread_join(producers[i], NULL);
	}

	//TODO
	printf("Deleting the semaphore\n");
    sem_destroy(semAcquisition);
	printf("[acquisitionManager]Semaphore cleaned\n");
}

void *produce(void* params)
{
	D(printf("[acquisitionManager]Producer created with id %d\n", gettid()));
	unsigned int i = 0;
	while (i < PRODUCER_LOOP_LIMIT)
	{
		i++;
		sleep(PRODUCER_SLEEP_TIME+(rand() % 5));
		//TODO
		printf("Trying to own the mutex\n");
    	pthread_mutex_lock(&mutex);
    	printf("Owns the mutex\n");
		getInput(gettid(), &msg_bloc); // get input message
		incrementProducedCount(); //incremente le nombre d'entree produit 
		break; // exit the loop when we get the message
	}
	printf("[acquisitionManager] %d termination\n", gettid());
	//TODO
	pthread_mutex_unlock(&mutex);
}