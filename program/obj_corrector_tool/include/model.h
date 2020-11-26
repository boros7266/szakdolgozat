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
    regex_t polygon_regex;
}Regular;

typedef struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_faces;
    int n_triangles;
    int n_quads;
    int n_polygons;
    struct Vertex* vertices;
    struct TextureVertex* texture_vertices;
    struct NormalVertex* normals;
    struct Triangle* triangles;
    struct Quad* quads;
}Model;

/**
 * Initializes model counters to zero.
 */
void init_model_counters(Model* model);

/**
 * Change model counters to one.
 */
void change_model_counters(Model* model);

/**
 * Load OBJ model from file.
 */
int load_model(char* filename, Model* model,Regular* regular);

/**
 * Compile the regular expression.
 */
void compile_regular_expressions(Regular* regular);

/**
 * Check that the given line of the OBJ file contains vertex data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on vertex line, else false
 */
bool is_vertex_line(const Regular* const regular, const char* const line);

/**
 * Check that the given line of the OBJ file contains texture vertex data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on texture vertex line, else false
 */
bool is_texture_vertex_line(const Regular* const regular, const char* const line);

/**
 * Check that the given line of the OBJ file contains normal vertex data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on normal vertex line, else false
 */
bool is_vertex_normal_line(const Regular* const regular, const char* const line);

/**
 * Check that the given line of the OBJ file contains face line data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on face line, else false
 */
bool is_face_line(const Regular* const regular, const char* const line);

/**
 * Check that the given line of the OBJ file contains triangle line data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on triangle line, else false
 */
bool is_triangle_line(const Regular* const regular, const char* const line);

/**
 * Check that the given line of the OBJ file contains quad line data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on quad line, else false
 */
bool is_quad_line(const Regular* const regular, const char* const line);
/**
 * Check that the given line of the OBJ file contains polygon line data.
 *
 * @param line: line of the OBJ file
 * @param regular: structure of compiled regular expressions
 * @return: true on polygon line, else false
 */
bool is_polygon_line(const Regular* const regular, const char* const line);

/**
 * Count the elements in the model and set counts in the structure.
 */
void count_elements(FILE* file,Model* model,Regular* regular);

/**
 * Print the information about the loaded model.
 */
void print_model_info(Model* model);

/**
 * Check that the next number is a number numeric.
 */
int is_numeric(char c);

/**
 * Read the given data from the line.
 */
void read_elements(FILE* file,Model* model, Regular* regular);

/**
 * Allocate memory for the model.
 */
void create_arrays(Model* model);

/**
 * Release the allocated memory of the model.
 */
void free_model(Model* model);

#endif /* MODEL_H */
