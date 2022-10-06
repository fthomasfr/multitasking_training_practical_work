#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h> 
#include "multitaskingAccumulator.h"
#include "acquisitionManager.h"
#include "displayManager.h"
#include "messageAdder.h"
#include "displayManager.h"	
#include "debug.h"


//The entry point of the process
int main( void )
{
	printf("[multitaskingAccumulator]Software initialization in progress...\n");	
	acquisitionManagerInit();
	messageAdderInit();
	displayManagerInit();
	printf("[multitaskingAccumulator]Task initialization done.\n");
	
	printf("[multitaskingAccumulator]Scheduling in progress...\n");

	displayManagerJoin();
	messageAdderJoin();
	acquisitionManagerJoin();

	printf("[multitaskingAccumulator]Threads terminated\n");

	exit(EXIT_SUCCESS);

}
