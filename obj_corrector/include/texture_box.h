#ifndef TEXTURE_BOX_H
#define TEXTURE_BOX_H

#include <string.h>
#include <stdlib.h>

typedef struct TextureBox
{
    double min_u;
    double max_u;
    double min_v;
    double max_v;
}TextureBox;

/**
 * Calculate the texture box of the model.
 */
void calc_texture_box(Model* model,TextureBox* texture_box);

/**
 * Print the texture box of the model.
 */
void print_texture_box(TextureBox* texture_box);

#endif /* TEXTURE_BOX_H */
