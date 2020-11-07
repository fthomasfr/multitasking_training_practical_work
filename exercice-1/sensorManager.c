#include "iSensor.h"
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"


void getInput(const unsigned int input, volatile MSG_BLOCK* mBlock){
	unsigned int i;
	unsigned int j  = input;
	D(printf("Get message for input %u \n",j));
	mBlock->checksum = 0;
	for(i=0;i < DATA_SIZE;i++){
		mBlock->mData[i] = rand();
		mBlock->checksum ^= mBlock->mData[i];
	}
	return;
}