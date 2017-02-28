#include "lfsr.h"

#define lfsr_seed  0x40
#define lfsrOutputMask  0x7f

char sequenceIndex = 0;
const lfsr_t xorSequences[] = {0x41,0x44,0x47,0x48,0x4E,0x53,0x55,0x5C,0x5F,0x60,0x65,0x69,0x6A,0x72,0x77,0x78,0x7B,0x7E};
lfsr_t xor_mask = 0x41;  // note this comes from the first entry in the sequence list
lfsr_t lfsr_value = lfsr_seed;

lfsr_t lfsr_getSequence(void)
{
	return xorSequences[sequenceIndex];
}

int lfsr_getSequenceCount(void)
{
	return sizeof(xorSequences)/sizeof(*xorSequences);
}

void lfsr_reset(void)
{
	lfsr_value = lfsr_seed;
}

void lfsr_setSequence(int s)
{
	s %= sizeof(xorSequences)/sizeof(*xorSequences);
	xor_mask = xorSequences[s];
}

lfsr_t lfsr(void)
{
	char lsb = lfsr_value & 1;
	lfsr_value >>= 1;
	if (lsb)
		lfsr_value ^= xor_mask;
	return lfsr_value & lfsrOutputMask;
}
