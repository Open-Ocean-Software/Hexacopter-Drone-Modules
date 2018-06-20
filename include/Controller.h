
#ifndef CONTROLLER_H
#define CONTROLLER_H

#ifndef F_CPU
#include "Config.h"
#define F_CPU CONFIG_F_CPU
#endif

/**
 * The main activity of the module while it is enabled.
 */
void Activity (void);

/**
 * The secondary activity of the module when it is disabled.
 */
void Standby (void);



/**
 * Starts the system timer.
 */
void InitializeStopwatch (void);

/**
 * Handles a system timer interrupt.
 */
void StopwatchHandler (void);

/**
 * Gives the current system time since power on or the last reset.
 * @return  The system time in milliseconds.
 */
double ReadStopwatch (void);

/**
 * Resets the current system time.
 */
void ResetStopwatch (void);

#endif
