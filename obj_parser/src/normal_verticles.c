#include <stdio.h>
#include "normal_verticles.h"

void normal_coords(struct NormalVertex* normalvertex)
{
    int i=0;
    FILE *archive;
    archive = fopen("Normal_output.txt","r");
    if (archive == NULL)
        exit(1);
    while (feof(archive) == 0)
    {
        fscanf(archive, "%lf %lf %lf", &normalvertex->x[i][0],&normalvertex->y[i][1],&normalvertex->z[i][2]);
    }
    fclose(archive);
    remove("Normal_output.txt");
}
