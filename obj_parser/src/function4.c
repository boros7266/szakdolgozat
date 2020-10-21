#include <stdio.h>
#include "functions.h"

void findSize() 
{	
    char* files[NrOfFiles2];
    files[0] ="asd.txt";
    files[1] ="asd2.txt";
    for(int i = 0; i < NrOfFiles2; i++)
    {
	FILE *fp;
	fp = fopen(files[i], "r");
	if (fp == NULL) { 
       		printf("Texture file Not Found!\n"); 
    		} 
	else
   			 {
        	printf("File opening successful!\nFile name: %s\n",files[i]);
    		}
	fseek(fp, 0L, SEEK_END); 
	int res = ftell(fp);
	fclose(fp);
        printf("Size of the file is %d bytes \n\n", res);
  }
    return; 
} 
