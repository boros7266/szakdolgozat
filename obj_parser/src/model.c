#include <stdio.h>
#include "model.h"
#include "vertices.h"
#include "texture_vertices.h"
#include "normal_vertices.h"
#include "triangles.h"
#include "quads.h"

const char *geometric_vertices  = "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *texture_coordinates = "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *vertex_normals      = "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *face_elements       = "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *space_vertices      = "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *triangles		= "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){3}[\\ ]*$";
const char *quads		= "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){4}[\\ ]*$";

void init_model_counters(Model* model)
{
    model->n_vertices = 0;
    model->n_texture_vertices = 0;
    model->n_normals = 0;
    model->n_faces = 0;
    model->n_spaces = 0;
    model->n_triangles = 0;
    model->n_quads = 0;
}

int load_model(char* filename, Model* model,Regular* regular, BoundingBox* bounding_box, TextureBox* texture_box)
{
    FILE* obj_file = fopen(filename, "r");
    printf("Load model\t%s\n", filename);
    if (obj_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return false;
    }
    	printf("Filename:\t%s\n",filename);
	count_elements(obj_file, model, regular);
	create_arrays(model);
        read_elements(obj_file, model, regular);
	count_bounding_box(model, bounding_box);
	count_texture_box(model, texture_box);
	return true;
}

void regex_check(Regular* regular)
{
    if (regcomp(&regular->re, geometric_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", geometric_vertices);
        return ;
    }
    else if (regcomp(&regular->re1, texture_coordinates, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", texture_coordinates);
        return ;
    }
    else if (regcomp(&regular->re2, vertex_normals, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", vertex_normals);
        return ;
    }
    else if (regcomp(&regular->re3, face_elements, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", face_elements);
        return ;
    }
    else if (regcomp(&regular->re4, space_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", space_vertices);
        return ;
    }
    else if (regcomp(&regular->re5, triangles, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", triangles);
        return ;
    }
    else if (regcomp(&regular->re6, quads, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", quads);
        return ;
    }
    else
    {
        printf("\nRegex compile completed!\n\n");
    }
}

void count_elements(FILE* file,Model* model,Regular* regular)
{
    init_model_counters(model);
    regex_check(regular);
    char* line = malloc(BUFFER_SIZE);
    int retval = 0;
    regmatch_t rm[2];
	while (fgets(line, BUFFER_SIZE, file) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&regular->re, line, 2, rm, 0)) == 0)
        {
          model->n_vertices++;
        }
        else if ((retval = regexec(&regular->re1, line, 2, rm, 0)) == 0)
        {
            model->n_texture_vertices++;
        }
        else if ((retval = regexec(&regular->re2, line, 2, rm, 0)) == 0)
        {
            model->n_normals++;
        }
        else if ((retval = regexec(&regular->re3, line, 2, rm, 0)) == 0)
        {
            model->n_faces++;
		if ((retval = regexec(&regular->re5, line, 2, rm, 0)) == 0)
		{
           	model->n_triangles++;
		}
		else if ((retval = regexec(&regular->re6, line, 2, rm, 0)) == 0)
       		{	
            	model->n_quads++;
        	}
        }
        else if ((retval = regexec(&regular->re4, line, 2, rm, 0)) == 0)
        {
           	model->n_spaces++;
        }
    }
}

int is_numeric(char c)
{
    if ((c >= '0' && c <= '9') || c == '-' || c == '.') {
        return true;
    }
    else {
        return false;
    }
}

void read_elements(FILE* file,Model* model, Regular* regular){
    init_model_counters(model);
    char* line = malloc(BUFFER_SIZE);
    int retval = 0;
    regmatch_t rm[2];
    fseek(file, 0, SEEK_SET);
	while (fgets(line, BUFFER_SIZE, file) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&regular->re, line, 2, rm, 0)) == 0)
        {
            read_vertex(&(model->vertices[model->n_vertices]), line);
            model->n_vertices++;
        }
        else if ((retval = regexec(&regular->re1, line, 2, rm, 0)) == 0)
        {
            read_texture_vertex(&(model->texture_vertices[model->n_texture_vertices]), line);
            model->n_texture_vertices++;
        }
        else if ((retval = regexec(&regular->re2, line, 2, rm, 0)) == 0)
        {
            read_normal(&(model->normals[model->n_normals]), line);
            model->n_normals++;
        }
        else if ((retval = regexec(&regular->re3, line, 2, rm, 0)) == 0)
        {
            model->n_faces++;
		if ((retval = regexec(&regular->re5, line, 2, rm, 0)) == 0)
		{
 		read_triangle(&(model->triangles[model->n_triangles]), line);
           	model->n_triangles++;
		}
		else if ((retval = regexec(&regular->re6, line, 2, rm, 0)) == 0)
       		{
		read_quad(&(model->quads[model->n_quads]), line);	
            	model->n_quads++;
        	}
        }
        else if ((retval = regexec(&regular->re4, line, 2, rm, 0)) == 0)
        {
           model->n_spaces++;
        }
    }

}

void create_arrays(Model* model)
{
    model->vertices =(Vertex*)malloc((model->n_vertices + 1) * sizeof(Vertex));
    model->texture_vertices =(TextureVertex*)malloc((model->n_texture_vertices + 1) * sizeof(TextureVertex));
    model->normals =(NormalVertex*)malloc((model->n_normals + 1) * sizeof(NormalVertex));
    model->triangles =(Triangle*)malloc(model->n_triangles * sizeof(Triangle));
    model->quads =(Quad*)malloc(model->n_quads * sizeof(Quad));
}

void print_model_info(Model* model)
{
    printf("Vertices:\t\t%d\n",model->n_vertices);
    printf("Texture vertices:\t%d\n",model->n_texture_vertices);
    printf("Vertex normals:\t\t%d\n",model->n_normals);
    printf("Face elements:\t\t%d\n",model->n_faces);
    printf("Space vertices:\t\t%d\n\n",model->n_spaces);
    printf("Triangles:\t\t%d\n",model->n_triangles);
    printf("Quads:\t\t\t%d\n\n",model->n_quads);
}

void count_bounding_box(Model* model,BoundingBox* bounding_box)
{
    int i;
    double x, y, z;

    if (model->n_vertices == 0) {
        return;
    }

    bounding_box->min_x = model->vertices[0].x;
    bounding_box->max_x = model->vertices[0].x;
    bounding_box->min_y = model->vertices[0].y;
    bounding_box->max_y = model->vertices[0].y;
    bounding_box->min_z = model->vertices[0].z;
    bounding_box->max_z = model->vertices[0].z;

    for (i = 0; i < model->n_vertices; ++i) {
        x = model->vertices[i].x;
        y = model->vertices[i].y;
        z = model->vertices[i].z;
        if (x < bounding_box->min_x) {
            bounding_box->min_x = x;
        }
        else if (x > bounding_box->max_x) {
            bounding_box->max_x = x;
        }
        if (y < bounding_box->min_y) {
            bounding_box->min_y = y;
        }
        else if (y > bounding_box->max_y) {
            bounding_box->max_y = y;
        }
        if (z < bounding_box->min_z) {
            bounding_box->min_z = z;
        }
        else if (z > bounding_box->max_z) {
            bounding_box->max_z = z;
        }
    }
}
void print_bounding_box(BoundingBox* bounding_box)
{
    printf("Bounding box:\n");
    printf("x in [%lf, %lf]\n", bounding_box->min_x, bounding_box->max_x);
    printf("y in [%lf, %lf]\n", bounding_box->min_y, bounding_box->max_y);
    printf("z in [%lf, %lf]\n\n", bounding_box->min_z, bounding_box->max_z);
}

void count_texture_box(Model* model,TextureBox* texture_box)
{
    int i;
    double u, v;

    if (model->n_texture_vertices == 0) {
        return;
    }

    texture_box->min_u = model->texture_vertices[0].u;
    texture_box->max_u = model->texture_vertices[0].u;
    texture_box->min_v = model->texture_vertices[0].v;
    texture_box->max_v = model->texture_vertices[0].v;

    for (i = 0; i < model->n_texture_vertices; ++i) {
        u = model->texture_vertices[i].u;
        v = model->texture_vertices[i].v;
        if (u < texture_box->min_u) {
            texture_box->min_u = u;
        }
        else if (u > texture_box->max_u) {
            texture_box->max_u = u;
        }
        if (v < texture_box->min_v) {
            texture_box->min_v = v;
        }
        else if (v > texture_box->max_v) {
            texture_box->max_v = v;
        }
    }
}

void print_texture_box(TextureBox* texture_box)
{
    printf("Texture box:\n");
    printf("u in [%lf, %lf]\n", texture_box->min_u, texture_box->max_u);
    printf("v in [%lf, %lf]\n", texture_box->min_v, texture_box->max_v);
}
