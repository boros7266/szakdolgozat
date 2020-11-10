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
    regex_t vertex_regex;
    regex_t texture_vertex_regex;
    regex_t vertex_normal_regex;
    regex_t face_regex;
    regex_t triangle_regex;
    regex_t quad_regex;
}Regular;

typedef struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_faces;
    int n_triangles;
    int n_quads;
    struct Vertex* vertices;
    struct TextureVertex* texture_vertices;
    struct NormalVertex* normals;
    struct Triangle* triangles;
    struct Quad* quads;
}Model;

void init_model_counters(Model* model);

void change_model_counters(Model* model);

int load_model(char* filename, Model* model,Regular* regular);

void regex_check(Regular* regular);

void count_elements(FILE* file,Model* model,Regular* regular);

void print_model_info(Model* model);

int is_numeric(char c);

void read_elements(FILE* file,Model* model, Regular* regular);

void create_arrays(Model* model);

void free_model(Model* model);

#endif /* MODEL_H */
