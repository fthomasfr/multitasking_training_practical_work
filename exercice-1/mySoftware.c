#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h> 
#include "mySoftware.h"
#include "acquisitionManager.h"
#include "displayManager.h"
#include "messageAdder.h"
#include "displayManager.h"	
#include "debug.h"


//The entry point of the process
int main( void )
{
	printf("[mySoftware]Software initialization in progress...\n");	
	acquisitionManagerInit();
	messageAdderInit();
	displayManagerInit();
	printf("[mySoftware]Task initialization done.\n");
	
	printf("[mySoftware]Scheduling in progress...\n");

	displayManagerJoin();
	messageAdderJoin();
	acquisitionManagerJoin();

	printf("[mySoftware]Threads terminated\n");

	exit(EXIT_SUCCESS);

}
