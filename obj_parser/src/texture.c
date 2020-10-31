#include <stdio.h>
#include <limits.h>
#include "functions.h"

void texture() {
  int i=0;
  char resultName[CHAR_MAX][CHAR_MAX];
  int n_textures =0;
  DIR *d;
  struct dirent *dir;
  char path[1000]="./";
  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
    if (!strcmp (dir->d_name, ".") || !strcmp (dir->d_name, ".."))
            continue;
      int length = strlen(dir->d_name);
      if ((strncmp(dir->d_name + length - 4, ".jpg", 4) == 0) || (strncmp(dir->d_name + length - 4, ".png", 4) == 0) || (strncmp(dir->d_name + length - 4, ".tga", 4) == 0)){
      strcpy(resultName[i], dir->d_name);
          n_textures++;
          i++;
      }
    }
	if(n_textures == 0)
        {
            printf("0 Texture files found!\n");
        }
        else{
            printf("Texture files found: %d\n\n", n_textures);
    }
    for( int i=0; i<n_textures;i++){
    printf("Textures:\t");
    puts (resultName[i]);
    }
    printf("\n");
    closedir(d);
  }
  for(int i = 0; i < n_textures; i++)
    {
    char* filename;
    filename =resultName[i];
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

