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
#define SEM_NAME "/sem_libre"
#define BUFF_SIZE 4 // total number of input 
#define SL_INITIAL_VALUE 4


volatile MSG_BLOCK msg_bloc[BUFF_SIZE]; // shared message bloc
int indiceLibre;       // indicate the empty input index
int indiceOccupee;     // indicate the nomber of fill input index
//producer count storage
_Atomic int produceCount = 0; // replace volatile with atomic for more thread safe operation

pthread_t producers[4];
static void *produce(void *params);

/**
* Semaphores and Mutex
*/
//TODO
sem_t  *SL;  // number of empty spot
sem_t *SCOM1; // getting the empty index
sem_t *SCOM2;  // giving the fill index
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
    SL = sem_open(SEM_NAME, O_CREAT, 0644, SL_INITIAL_VALUE);
	SCOM1 = sem_open("/sem_com1", O_CREAT, 0644, 1);
	SCOM2 = sem_open("/sem_com2", O_CREAT, 0644, 1);
	if (SL == SEM_FAILED){
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
	return msg_bloc[indiceOccupee];
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
		printf("Creating the producers thread\n");
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
		printf("Waiting for all the producer thread end\n");
		pthread_join(producers[i], NULL);
	}

	//TODO
	printf("Deleting the semaphore\n");
	sem_destroy(SCOM1);
	sem_destroy(SCOM2);
    sem_destroy(SL);
	printf("[acquisitionManager]Semaphore cleaned\n");
}

void *produce(void* params)
{
	D(printf("[acquisitionManager]Producer created with id %d\n", gettid()));
	unsigned int i = 0;
	int currentIndex = 0; // local input index
	int j = 0; // compteur for number of input
	MSG_BLOCK currentMsg; // message provided
	while (i < PRODUCER_LOOP_LIMIT)
	{
		i++;
		sleep(PRODUCER_SLEEP_TIME+(rand() % 5));
		//TODO
		getInput(gettid(), &currentMsg);
		if(!messageCheck(&currentMsg)){
			continue;
		}
		sem_wait(SL);
		sem_wait(SCOM1);
		currentIndex = indiceLibre;
		indiceLibre = (indiceLibre+1)%BUFF_SIZE;
		sem_post(SCOM1);
		msg_bloc[currentIndex] = currentMsg;
		printf("Trying to own the mutex\n");
    	pthread_mutex_lock(&mutex);
    	printf("Owns the mutex\n");
		incrementProducedCount(); //incremente le nombre d'entree produit 
		pthread_mutex_unlock(&mutex);
		sem_wait(SCOM2);
		indiceOccupee=currentIndex;
		indiceOccupee = (indiceOccupee+1)%BUFF_SIZE;
		sem_post(SCOM2);
	}
	printf("[acquisitionManager] %d termination\n", gettid());
	//TODO
	pthread_exit(NULL);
}