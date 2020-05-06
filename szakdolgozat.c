#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <regex.h>

#define geometric_vertices    "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //List of geometric vertices
#define texture_coordinates  "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of texture coordinates
#define vertex_normals       "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of vertex normals
#define space_vertices       "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //Parameter space vertices
#define face_elements        "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //Polygonal face elements

int main(int argc, char **argv)
{
    FILE *fp;
    char line[999999];
    int retval = 0;
    regex_t re,re1,re2,re3,re4;
    regmatch_t rm[2];
    const char *filename = "12221_Cat_v1_l3.obj";
    int count=0,count1=0,count2=0,count3=0,count4=0;

    if (argc > 1)
        filename = argv[1];

    if (regcomp(&re, geometric_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", geometric_vertices);
        return EXIT_FAILURE;
    }
    else if (regcomp(&re1, texture_coordinates, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", texture_coordinates);
        return EXIT_FAILURE;
    }
    else if (regcomp(&re2, vertex_normals, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", vertex_normals);
        return EXIT_FAILURE;
    }
    else if (regcomp(&re3, space_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", space_vertices);
        return EXIT_FAILURE;
    }
    else if (regcomp(&re4, face_elements, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", face_elements);
        return EXIT_FAILURE;
    }
    else
    {
        printf("Regex compile completed!\n");
    }
    fp = fopen(filename, "r");
    if (fp == 0)
    {
        fprintf(stderr, "Failed to open obj %s (%d: %s)\n", filename, errno, strerror(errno));
        return EXIT_FAILURE;
    }
    else
    {
        printf("File opening successful!\nFile name: %s\n\n",filename);
    }

    FILE *frp;
    frp=fopen("Output.txt", "w");

    while ((fgets(line, 999999, fp)) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count++;
        }
        else if ((retval = regexec(&re1, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count1++;
        }
        else if ((retval = regexec(&re2, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count2++;
        }
        else if ((retval = regexec(&re3, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count3++;
        }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count4++;
        }
    }
    fclose (fp);
    printf("Geometric vertices: %d\n",count);
    printf("Texture coordinates: %d\n",count1);
    printf("Vertex normals: %d\n",count2);
    printf("Space vertices: %d\n",count3);
    printf("Face elements: %d\n",count4);
    return EXIT_SUCCESS;
}
