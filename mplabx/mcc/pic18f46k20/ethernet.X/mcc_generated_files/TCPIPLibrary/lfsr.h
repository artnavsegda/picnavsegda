#ifndef __LFSR_H
#define __LFSR_H
#include <stdint.h>

typedef uint8_t lfsr_t;
int lfsr_getSequenceCount(void);
lfsr_t lfsr_getSequence(void);
void lfsr_reset(void);
void lfsr_setSequence(int s);
lfsr_t lfsr(void);

#endif // __LFSR_H
