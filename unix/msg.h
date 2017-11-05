#include <stdio.h>
#include <pthread.h>

//Message data size
#define DATA_SIZE 256
#define DWORD	unsigned int

//producer and consumer count storage
volatile DWORD consumeCount, produceCount;

//message type definition
typedef struct MSG_BLOCK_TAG
{
	pthread_t threadID;
	time_t timestamp;
	DWORD checksum;
	DWORD mData[DATA_SIZE];
} MSG_BLOCK;

/**
* Set the message content. The mBlock timestamp is not set by that function, user has to set it.
* @param mBlock the message pointer
* @param threadId the thread id that produce the message
*/
void MessageFill(volatile MSG_BLOCK* mBlock, pthread_t threadId);

/**
* Display the message content
* @param mBlock the message pointer
*/
void MessageDisplay(volatile MSG_BLOCK* mBlock);
