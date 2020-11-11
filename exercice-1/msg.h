#ifndef MSG_H
#define MSG_H

//Message data size
#define DATA_SIZE 256

//message type definition
typedef struct MSG_BLOCK_TAG
{
	unsigned int checksum;
	unsigned int mData[DATA_SIZE];
} MSG_BLOCK;

/**
* Displays the message content
* @param mBlock the message pointer
* @return 1 if the checksum is ok, 0 otherwise
*/
unsigned int messageCheck(volatile MSG_BLOCK* mBlock);

/**
* Adds to the src message the content of add message
* @param src the message pointer
* @param add the message to add
*/
void messageAdd(volatile MSG_BLOCK* src, volatile MSG_BLOCK* add);

#endif
