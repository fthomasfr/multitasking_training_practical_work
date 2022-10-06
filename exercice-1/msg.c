#include <stdlib.h>
#include <stdio.h>
#include "msg.h"
#include "debug.h"


/**
* Add to the src message the content of add message
* @param src the message pointer
* @param add the message to add
*/
void messageAdd(volatile MSG_BLOCK* src, volatile MSG_BLOCK* add){
	unsigned int i;
	src->checksum = 0;
	for(i=0;i < DATA_SIZE;i++){
		src->mData[i] += add->mData[i];
		src->checksum ^= src->mData[i];
	}
	D(printf("[msg]....Sum done...\n"));
}

/**
* Display the message content
* @param mBlock the message pointer
*/
unsigned int messageCheck(volatile MSG_BLOCK* mBlock){
	unsigned int i, tcheck=0;
	for(i=0;i < DATA_SIZE;i++)
		tcheck ^= mBlock->mData[i];
	if(tcheck == mBlock->checksum){
		printf("[OK      ] Checksum validated\n");
		return 1;
	}else{
		printf("[  FAILED] Checksum failed, message corrupted\n");
		return 0;
	}
}
