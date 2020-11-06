#ifndef TIME_H
#define TIME_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

struct timeval start, finish;

void begin();
void end();

#endif /* TIME_H */
