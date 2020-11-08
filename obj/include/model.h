#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>
#include <stdbool.h>


#define BUFFER_SIZE 1024

typedef struct Regular
{
    regex_t re;
    regex_t re1;
    regex_t re2;
    regex_t re3;
    regex_t re4;
}Regular;

typedef struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_spaces;
    int n_faces;
    struct Vertex* vertices;
    struct TextureVertex* texture_vertices;
    struct NormalVertex* normals;
}Model;

typedef struct BoundingBox
{
    double min_x;
    double min_y;
    double min_z;
    double max_x;
    double max_y;
    double max_z;
}BoundingBox;

typedef struct TextureBox
{
    double min_u;
    double max_u;
    double min_v;
    double max_v;
}TextureBox;



int load_model(char* filename, Model* model,Regular* regular,BoundingBox* bounding_box,TextureBox* texture_box);

void regex_check(Regular* regular);

void count_elements(FILE* file,Model* model,Regular* regular);

void print_model_info(Model* model);

int is_numeric(char c);

void read_elements(FILE* file,Model* model, Regular* regular);

void create_arrays(Model* model);

void free_model(Model* model);

void count_bounding_box(Model* model,BoundingBox* bounding_box);

void print_bounding_box(BoundingBox* bounding_box);

void count_texture_box(Model* model,TextureBox* texture_box);

void print_texture_box(TextureBox* texture_box);

#endif /* MODEL_H */
