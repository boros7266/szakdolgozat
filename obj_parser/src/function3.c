#include <stdio.h>
#include "functions.h"

void end(){

	gettimeofday(&finish, NULL);
	long seconds = (finish.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + finish.tv_usec) - (start.tv_usec);
	printf("Time elpased is %ld seconds and %ld microseconds\n", seconds, micros);

	printf("\nProgram Succesfully Ended\n");
}
