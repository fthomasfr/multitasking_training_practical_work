#include "iDisplay.h"
#include <stdlib.h>
#include <stdio.h>
#include "debug.h"

void messageDisplay(volatile MSG_BLOCK* mBlock){
	unsigned int i; 
	messageCheck(mBlock);
	printf("Message\n");
	D(printf("["));
	for(i=0;i < DATA_SIZE;i++)
		D(printf("%u ",mBlock->mData[i]));
	D(printf("]\n"));
}

void print(unsigned int producedCount, unsigned int consumedCount){
	printf("[displayManager]Produced messages: %d, Consumed messages: %d, Messages left: %d\n", producedCount, consumedCount, producedCount - consumedCount);
}