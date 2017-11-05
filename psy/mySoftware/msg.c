#include "msg.h"

/**
* Set the message content
* @param mBlock the message pointer
* @param threadId the thread id that produce the message
*/
void MessageFill(MSG_BLOCK* mBlock, DWORD threadId){
	DWORD i;
	mBlock->checksum = 0;
	for(i=0;i < DATA_SIZE;i++){
		mBlock->mData[i] = rand();
		mBlock->checksum ^= mBlock->mData[i];
	}
	mBlock->threadID = threadId;
	return;
}

/**
* Display the message content
* @param mBlock the message pointer
*/
void MessageDisplay(MSG_BLOCK* mBlock){
	DWORD i, tcheck=0;
	for(i=0;i < DATA_SIZE;i++)
		tcheck ^= mBlock->mData[i];
	if(tcheck == mBlock->checksum)
		printf("[OK      ] Checksum validated\n");
	else
		printf("[  FAILED] Checksum failed, message corrupted\n");

}