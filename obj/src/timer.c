#include <stdio.h>
#include "timer.h"


void timer_start(){
	printf("\nProgram Started!\n");
	gettimeofday(&start, NULL);
}
void timer_finish(){

	gettimeofday(&finish, NULL);
	long seconds = (finish.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + finish.tv_usec) - (start.tv_usec);
	printf("\nTime elpased is %ld seconds and %ld microseconds\n", seconds, micros);

	printf("\nProgram Succesfully Ended\n");
}
