#ifndef LIGHTNING_OVERFLOWS_H
#define LIGHTNING_OVERFLOWS_H
#include "config.h"

static inline bool add_overflows_size_t(uint64_t a, uint64_t b)
{
	return (size_t)a != a || (size_t)b != b || (a + b) < (size_t)a;
}

static inline bool add_overflows_u64(uint64_t a, uint64_t b)
{
	return (a + b) < a;
}

static inline bool mul_overflows_s64(int64_t a, int64_t b)
{
	int64_t ret;

	if (a == 0)
		return false;
	ret = a * b;
	return (ret / a != b);
}
#endif /* LIGHTNING_OVERFLOWS_H */
