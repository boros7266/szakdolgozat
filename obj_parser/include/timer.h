#ifndef TIMER_H
#define TIMER_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

struct timeval start, finish;

void start_timer();

void calc_timer_elapsed_time();

#endif /* TIMER_H */
