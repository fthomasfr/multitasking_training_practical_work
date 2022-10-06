#ifndef I_DISPLAY_H
#define I_DISPLAY_H

#include "msg.h"

/**
* Displays the message content
* @param mBlock the message pointer
*/
void messageDisplay(volatile MSG_BLOCK* mBlock);

/**
* Prints the number of produced and consumed messages. It prints also the difference.
* @param producedCount the number of produced messages
* @param consumedCount the number of consumed messages
*/
void print(unsigned int producedCount, unsigned int consumedCount);

#endif