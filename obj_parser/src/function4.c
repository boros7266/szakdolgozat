#include <stdio.h>
#include "functions.h"
#include <SOIL/SOIL.h>


void findSize()
{
    char* filename;
    filename ="/home/bence/Asztal/obj_parser/5.png";
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
       		printf("Texture file Not Found!\n");
    		}
	else
   			 {
        	printf("File opening successful!\nFile name: %s\n",filename);
    		}
	fseek(fp, 0L, SEEK_END);
	int res = ftell(fp);
	fclose(fp);
        printf("Size of the file is %d bytes \n\n", res);


    int width;
    int height;

    Pixel* image = (Pixel*)SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
    printf("Width:\t%d\n",width);
    printf("Height:\t%d\n",height);
    return ;
}
