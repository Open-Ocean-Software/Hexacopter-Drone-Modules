
#ifndef PWMHELPER_H
#define PWMHELPER_H

/**
 * Helps PWM modules handle their duty cycles.
 * @param mod A pointer to the module.
 * @param t   The current time progress through the duty cycle.
 */
void PWMHandlerHelper (Module *mod, unsigned char t);

#endif
