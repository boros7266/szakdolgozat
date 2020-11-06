#include <stdio.h>
#include "texture_verticles.h"

void texture_coords(struct TextureVertex* texturevertex)
{
    int i=0;
    FILE *archive;
    archive = fopen("Texture_output.txt","r");
    if (archive == NULL)
        exit(1);
    while (feof(archive) == 0)
    {
        fscanf(archive, "%lf %lf", &texturevertex->u[i][0],&texturevertex->v[i][1]);
    }
    fclose(archive);
    remove("Texture_output.txt");
}
