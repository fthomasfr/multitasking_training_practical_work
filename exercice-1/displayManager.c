#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "displayManager.h"
#include "iDisplay.h"
#include "iAcquisitionManager.h"
#include "iMessageAdder.h"
#include "msg.h"
#include "multitaskingAccumulator.h"
#include "debug.h"

// DisplayManager thread.
pthread_t displayThread;

/**
 * Display manager entry point.
 * */
static void *display( void *parameters );


void displayManagerInit(void){
	//TODO
	printf("Creating the dispaly thread\n");
    pthread_create(&displayThread, NULL, display, NULL);
}

void displayManagerJoin(void){
	//TODO
	printf("Waiting the display thread end\n");
	pthread_join(displayThread, NULL);	
} 

static void *display( void *parameters )
{
	D(printf("[displayManager]Thread created for display with id %d\n", gettid()));
	unsigned int diffCount = 0;
	while(diffCount < DISPLAY_LOOP_LIMIT){
		sleep(DISPLAY_SLEEP_TIME);
		//TODO
		MSG_BLOCK msg = getCurrentSum();
		print(getProducedCount(), getConsumedCount());
		messageDisplay(&msg);
	}
	printf("[displayManager] %d termination\n", gettid());
   //TODO
   pthread_exit(NULL);
}