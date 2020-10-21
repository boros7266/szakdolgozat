#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <regex.h>

#define geometric_vertices      "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //List of geometric vertices
#define vertex_normals          "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of texture coordinates
#define texture_coordinates     "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of vertex normals
#define face_elements           "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //Polygonal face elements
#define space_vertices          "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //Parameter space vertices
#define NrOfFiles 1

int main()
{
    char* files[NrOfFiles];
    files[0] ="fish.obj";
    files[1] ="10050_RattleSnake_v4_L3.obj";
    files[2] ="garfield.obj";
    files[3] ="Output.obj";
    files[4] ="cube.obj";
    files[5] ="12190_Heart_v1_L3.obj";
    files[6] ="Stone.obj";
    //files[7] ="12248_Bird_v1_L2.obj";
    //filename = "fish.obj";
    FILE *frp2;
    frp2=fopen("Output.ods", "w");
    fprintf(frp2,"File name \t Vertices \t Texture vertices \t Vertex normals \t Face elements \t Space vertices \t z_min \t z_max \t z_size\n");
    for(int i = 0; i < NrOfFiles; i++)
    {
    FILE *fp;
    char line[999999];
    int retval = 0;
    regex_t re,re1,re2,re3,re4;
    regmatch_t rm[2];
    int count=0,count1=0,count2=0,count3=0,count4=0;
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
    else if (regcomp(&re3, face_elements, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", face_elements);
        return EXIT_FAILURE;
    }
    else if (regcomp(&re4, space_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", space_vertices);
        return EXIT_FAILURE;
    }
    else
    {
        printf("Regex compile completed!\n");
    }
    fp = fopen(files[i], "r");
    if (fp == 0)
    {
        fprintf(stderr, "Failed to open obj %s (%d: %s)\n", files[i], errno, strerror(errno));
        return EXIT_FAILURE;
    }
    else
    {
        printf("File opening successful!\nFile name: %s\n\n",files[i]);
    }
    FILE *frp;
    frp=fopen("Output.txt", "w");
    while ((fgets(line, 2147483647, fp)) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
          fprintf(frp,"%s",line + rm[1].rm_so);
          fprintf(frp,"\n");
          count++;
        }
        else if ((retval = regexec(&re1, line, 2, rm, 0)) == 0)
        {
            count1++;
        }
        else if ((retval = regexec(&re2, line, 2, rm, 0)) == 0)
        {
            count2++;
        }
        else if ((retval = regexec(&re3, line, 2, rm, 0)) == 0)
        {
            count3++;
        }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
            count4++;
        }
    }
    fclose (frp);
    frp=fopen("Output.txt", "r");
    double tomb[count];
    long int j;
    double z_max =0;
    double z_min =0;
    for (j=0; j < count ;j++){
    fscanf(frp, "%lf",&tomb[j]);
    //printf("%lf\n",tomb[j]);

        if(tomb[j] > z_max){
       z_max = tomb[j];
    }
    if(tomb[j] < z_min )
        z_min = tomb[j];
    }
    double z_sub = 0;
    z_sub = z_max - z_min;
    /*printf("\n%lf\n",z_min);
    printf("\n%lf\n",z_max);
    printf("\n%lf\n",z_sub);*/
    fclose (fp);
    /*printf("Vertices:\t\t%d\n",count);
    printf("Texture vertices:\t%d\n",count1);
    printf("Vertex normals:\t\t%d\n",count2);
    printf("Space vertices:\t\t%d\n",count3);
    printf("Face elements:\t\t%d\n",count4);*/
    fprintf(frp2,"%s \t %d \t %d \t %d \t %d \t %d\t %.2lf \t %.2lf \t %.2lf\n",files[i],count,count1,count2,count3,count4,z_min,z_max,z_sub);
    fclose (frp);
}
    fclose (frp2);
    return EXIT_SUCCESS;
}
