#ifndef TIMER_H
#define TIMER_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

struct timeval start, finish;

void timer_start();
void timer_finish();

#endif /* TIMER_H */
