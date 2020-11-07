#ifndef ACQUISITION_MANAGER_H
#define ACQUISITION_MANAGER_H

/**
* Initializes the acquisitions
*/
unsigned int acquisitionManagerInit(void);

/**
* Waits that acquisitions terminate
*/
void acquisitionManagerJoin(void);

#endif