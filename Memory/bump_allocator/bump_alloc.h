#ifndef BUMP_ALLOC_H
#define BUMP_ALLOC_H

#include <stdlib.h>

int bump_reset(void);
void *bump_alloc(size_t size);

#endif
