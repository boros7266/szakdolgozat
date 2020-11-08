#include <stdio.h>
#include "timer.h"


void start_timer()
{
	printf("\nProgram Started!\n");
	gettimeofday(&start, NULL);
}

void calc_timer_elapsed_time()
{

	gettimeofday(&finish, NULL);
	long seconds = (finish.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + finish.tv_usec) - (start.tv_usec);
	printf("\nTime elapsed is %ld seconds and %ld microseconds\n", seconds, micros);

	printf("\nProgram Succesfully Ended\n");
}
