#include <stdio.h>
#include "functions.h"

void texture() {
  int n_textures =0;
  DIR *d;
  struct dirent *dir;
  char path[1000]="./OBJ";
  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      int length = strlen(dir->d_name);
      if (strncmp(dir->d_name + length - 4, ".jpg", 4) == 0) {
          puts(dir->d_name);
          n_textures++;
      }
      else if (strncmp(dir->d_name + length - 4, ".png", 4) == 0) {
          puts(dir->d_name);
          n_textures++;
      }
      else if (strncmp(dir->d_name + length - 4, ".tga", 4) == 0) {
          puts(dir->d_name);
          n_textures++;
        }
    }
    if(n_textures == 0)
        {
            printf("0 Texture files found!\n");
        }
        else{
            printf("\nTexture files found: %d\n\n", n_textures);
    }
    closedir(d);
  }
  for(int i = 0; i < 1; i++)
    {
    char* filename;
    filename ="./OBJ/5.png";
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
    printf("Height:\t%d\n\n",height);
    }
  return;
}

