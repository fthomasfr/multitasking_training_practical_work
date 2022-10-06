#ifndef MULTITASKING_ACCUMULATOR_H
#define MULTITASKING_ACCUMULATOR_H

#include "msg.h"

//The application return code
#define ERROR_INIT 			1
#define ERROR_SUCCESS		0
//The number of producers
#define PRODUCER_COUNT      4
//The number of second the producer shall sleep
#define PRODUCER_SLEEP_TIME 1
//The number producer iterations
#define PRODUCER_LOOP_LIMIT 2
//The number of second the display shall sleep
#define DISPLAY_SLEEP_TIME  3
//The number display iterations
#define DISPLAY_LOOP_LIMIT  2
//The number of second the adder shall sleep
#define ADDER_SLEEP_TIME    2
//The number adder iterations
#define ADDER_LOOP_LIMIT    PRODUCER_LOOP_LIMIT * PRODUCER_COUNT * PRODUCER_SLEEP_TIME

#endif