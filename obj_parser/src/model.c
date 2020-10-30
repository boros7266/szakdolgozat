#include <stdio.h>
#include "functions.h"


#define BUFFER 1024


void OBJ_LOAD(){
    char* files[NrOfFiles];
    files[0] ="OBJ/12190_Heart_v1_L3.obj";
    files[1] ="OBJ/12248_Bird_v1_L2.obj";
    files[2] ="OBJ/cube.obj";
    files[3] ="OBJ/fish.obj";
    files[4] ="OBJ/Output.obj";

    for(int i = 0; i < NrOfFiles; i++)
    {
    FILE *fp;
    char* line = malloc(BUFFER);
    int retval = 0;
    regex_t re,re1,re2,re3,re4,re5,re6;
    regmatch_t rm[2];
    int n_vertices=0,n_normals=0,n_texture_vertices=0,n_faces=0,n_space=0,n_triangles=0,n_quads=0;

    if (regcomp(&re, geometric_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", geometric_vertices);
        return ;
    }
    else if (regcomp(&re1, texture_coordinates, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", texture_coordinates);
        return ;
    }
    else if (regcomp(&re2, vertex_normals, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", vertex_normals);
        return ;
    }
    else if (regcomp(&re3, face_elements, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", face_elements);
        return ;
    }
    else if (regcomp(&re4, space_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", space_vertices);
        return ;
    }
   else if (regcomp(&re5, triangles, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", triangles);
        return ;
    }
   else if (regcomp(&re6, quads, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", quads);
        return ;
    }
    else
    {
        printf("Regex compile completed!\n");
    }
    fp = fopen(files[i], "r");
    if (fp == 0)
    {
        fprintf(stderr, "Failed to open obj %s (%d: %s)\n", files[i], errno, strerror(errno));
        return ;
    }
    else
    {
        printf("File opening successful!\nFile name: %s\n\n",files[i]);
    }
    FILE *frp;
    frp=fopen("Output.txt", "w");
    while (fgets(line, BUFFER, fp) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
	  fprintf(frp,"%s",line + 2);
          fprintf(frp,"\n");
          n_vertices++;
        }
        else if ((retval = regexec(&re1, line, 2, rm, 0)) == 0)
        {
            n_normals++;
        }
        else if ((retval = regexec(&re2, line, 2, rm, 0)) == 0)
        {
            n_texture_vertices++;
        }
        else if ((retval = regexec(&re3, line, 2, rm, 0)) == 0)
        {
	    n_faces++;
		if ((retval = regexec(&re5, line, 2, rm, 0)) == 0)
		{
           	n_triangles++;
		}
        	
		else if ((retval = regexec(&re6, line, 2, rm, 0)) == 0)
       		 {	
            		n_quads++;
        		}
        }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
           	n_space++;
	}
    }
	    fclose (frp);
    int i=0;
    int j=0;
    double max_x,min_x,max_y,min_y,max_z,min_z;
    double value[n_vertices][2];
    FILE *archive;
    archive = fopen("Output.txt","r");
    if (archive == NULL)
        exit(1);
    while (feof(archive) == 0)
    {
        fscanf( archive, "%lf %lf %lf", &value[i][0],&value[i][1],&value[i][2]);
        //printf("%f %f %f\n", value[i][0], value[i][1],value[i][2]);
        for (j=0; j < n_vertices ;j++){
        if(value[i][0] < min_x){
            min_x = value[i][0];
            }
        else if(value[i][0] > max_x){
            max_x = value[i][0];
            }
        if(value[i][1] < min_y){
            min_y = value[i][1];
            }
        else if(value[i][1] > max_y){
            max_y = value[i][1];
            }
        if(value[i][2] < min_z){
            min_z = value[i][2];
	}
        else if(value[i][2] > max_z){
            max_z = value[i][2];
            }
        }
    }
    fclose(archive);
    fclose (fp);
    printf("Vertices:\t\t%d\n",n_vertices);
    printf("Texture vertices:\t%d\n",n_normals);
    printf("Vertex normals:\t\t%d\n",n_texture_vertices);
    printf("Face elements:\t\t%d\n",n_faces);
    printf("Space vertices:\t\t%d\n\n",n_space);
    printf("Triangles:\t\t%d\n",n_triangles);
    printf("Quads:\t\t\t%d\n\n",n_quads);
    printf("Bounding Box:\n");
    printf("x\t(%lf, %lf)\n", min_x, max_x);
    printf("y\t(%lf, %lf)\n", min_y, max_y);
    printf("z\t(%lf, %lf)\n", min_z, max_z);
    printf("x size =\t%lf\n",max_x-min_x);
    printf("y size =\t%lf\n",max_y-min_y);
    printf("z size =\t%lf\n\n",max_z-min_z);
}
return ;
}

