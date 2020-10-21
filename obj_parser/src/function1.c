#include <stdio.h>
#include "functions.h"


#define BUFFER 1024

void OBJ_LOAD(){
    char* files[NrOfFiles];
    files[0] ="OBJ/cube.obj";
    files[1] ="OBJ/Output.obj";
    files[2] ="OBJ/garfield.obj";
    files[3] ="OBJ/Output.obj";
    files[4] ="OBJ/cube.obj";
    files[5] ="OBJ/12190_Heart_v1_L3.obj";

    for(int i = 0; i < NrOfFiles; i++)
    {
    FILE *fp;
    //filename = "fish.obj";
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
        	
		 if ((retval = regexec(&re6, line, 2, rm, 0)) == 0)
       		 {
			fprintf(frp,"%s",line + rm[0].rm_so);
          		fprintf(frp,"\n");
            		n_quads++;
			n_triangles--;
        		}
        }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
           	n_space++;
	}
	
    }
    fclose (fp);
    printf("Vertices:\t\t%d\n",n_vertices);
    printf("Texture vertices:\t%d\n",n_normals);
    printf("Vertex normals:\t\t%d\n",n_texture_vertices);
    printf("Face elements:\t\t%d\n",n_faces);
    printf("Space vertices:\t\t%d\n\n",n_space);
    printf("Triangles:\t\t%d\n",n_triangles);
    printf("Quads:\t\t\t%d\n\n",n_quads);
}
return ;
}

