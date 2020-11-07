#ifndef I_SENSOR_H
#define I_SENSOR_H

#include "msg.h"

/**
* Gets the input message.
* @param input the input number
* @param mBlock the message pointer returned
*/
void getInput(const unsigned int input, volatile MSG_BLOCK* mBlock);

#endif
