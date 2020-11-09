#include <stdio.h>
#include "model.h"
#include "vertex.h"
#include "texture_vertex.h"
#include "normal_vertex.h"
#include "triangle.h"
#include "quad.h"
#include "bounding_box.h"
#include "texture_box.h"

const char *VERTEX_LINE_PATTERN 	= "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *TEXTURE_VERTEX_LINE_PATTERN = "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *VERTEX_NORMAL_LINE_PATTERN  = "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *FACE_LINE_PATTERN     	= "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*";
const char *TRIANGLE_LINE_PATTERN	= "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){3}[\\ ]*$";
const char *QUAD_LINE_PATTERN		= "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){4}[\\ ]*$";

void init_model_counters(Model* model)
{
    model->n_vertices = 0;
    model->n_texture_vertices = 0;
    model->n_normals = 0;
    model->n_faces = 0;
    model->n_triangles = 0;
    model->n_quads = 0;
}

int load_model(char* filename, Model* model,Regular* regular)
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
	return true;
}

void regex_check(Regular* regular)
{
    if (regcomp(&regular->vertex_regex, VERTEX_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", VERTEX_LINE_PATTERN);
        return ;
    }
    else if (regcomp(&regular->texture_vertex_regex, TEXTURE_VERTEX_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", TEXTURE_VERTEX_LINE_PATTERN);
        return ;
    }
    else if (regcomp(&regular->vertex_normal_regex, VERTEX_NORMAL_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", VERTEX_NORMAL_LINE_PATTERN);
        return ;
    }
    else if (regcomp(&regular->face_regex, FACE_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", FACE_LINE_PATTERN);
        return ;
    }
    else if (regcomp(&regular->triangle_regex, TRIANGLE_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", TRIANGLE_LINE_PATTERN);
        return ;
    }
    else if (regcomp(&regular->quad_regex, QUAD_LINE_PATTERN, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", QUAD_LINE_PATTERN);
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
        if ((retval = regexec(&regular->vertex_regex, line, 2, rm, 0)) == 0)
        {
          model->n_vertices++;
        }
        else if ((retval = regexec(&regular->texture_vertex_regex, line, 2, rm, 0)) == 0)
        {
            model->n_texture_vertices++;
        }
        else if ((retval = regexec(&regular->vertex_normal_regex, line, 2, rm, 0)) == 0)
        {
            model->n_normals++;
        }
        else if ((retval = regexec(&regular->face_regex, line, 2, rm, 0)) == 0)
        {
            model->n_faces++;
		if ((retval = regexec(&regular->triangle_regex, line, 2, rm, 0)) == 0)
		{
           	model->n_triangles++;
		}
		else if ((retval = regexec(&regular->quad_regex, line, 2, rm, 0)) == 0)
       		{	
            	model->n_quads++;
        	}
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
        if ((retval = regexec(&regular->vertex_regex, line, 2, rm, 0)) == 0)
        {
            read_vertex(&(model->vertices[model->n_vertices]), line);
            model->n_vertices++;
        }
        else if ((retval = regexec(&regular->texture_vertex_regex, line, 2, rm, 0)) == 0)
        {
            read_texture_vertex(&(model->texture_vertices[model->n_texture_vertices]), line);
            model->n_texture_vertices++;
        }
        else if ((retval = regexec(&regular->vertex_normal_regex, line, 2, rm, 0)) == 0)
        {
            read_normal(&(model->normals[model->n_normals]), line);
            model->n_normals++;
        }
        else if ((retval = regexec(&regular->face_regex, line, 2, rm, 0)) == 0)
        {
            model->n_faces++;
		if ((retval = regexec(&regular->triangle_regex, line, 2, rm, 0)) == 0)
		{
 		read_triangle(&(model->triangles[model->n_triangles]), line);
           	model->n_triangles++;
		}
		else if ((retval = regexec(&regular->quad_regex, line, 2, rm, 0)) == 0)
       		{
		read_quad(&(model->quads[model->n_quads]), line);	
            	model->n_quads++;
        	}
        }
    }

}

void create_arrays(Model* model)
{
    model->vertices =(Vertex*)malloc(model->n_vertices * sizeof(Vertex));
    model->texture_vertices =(TextureVertex*)malloc(model->n_texture_vertices * sizeof(TextureVertex));
    model->normals =(NormalVertex*)malloc(model->n_normals * sizeof(NormalVertex));
    model->triangles =(Triangle*)malloc(model->n_triangles * sizeof(Triangle));
    model->quads =(Quad*)malloc(model->n_quads * sizeof(Quad));
}

void print_model_info(Model* model)
{
    printf("Vertices:\t\t%d\n",model->n_vertices);
    printf("Texture vertices:\t%d\n",model->n_texture_vertices);
    printf("Vertex normals:\t\t%d\n",model->n_normals);
    printf("Face elements:\t\t%d\n\n",model->n_faces);
    printf("Triangles:\t\t%d\n",model->n_triangles);
    printf("Quads:\t\t\t%d\n\n",model->n_quads);
}

void free_model(struct Model* model)
{
    free(model->vertices);
    free(model->texture_vertices);
    free(model->normals);
    free(model->triangles);
    free(model->quads);
}
