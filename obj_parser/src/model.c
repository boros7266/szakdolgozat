#include <stdio.h>
#include "model.h"

int load_model(char* filename,struct Model* model)
{
    FILE* obj_file = fopen(filename, "r");
    printf("Load model\t%s\n", filename);
    if (obj_file == NULL) {
        printf("ERROR: Unable to open '%s' file!\n", filename);
    	return FALSE;
    }
    printf("Filename:\t%s\n",filename);
        n_coords(obj_file, model);
	return TRUE;
}

void init_model_counters(struct Model* model)
{
    model->n_vertices = 0;
    model->n_texture_vertices = 0;
    model->n_normals = 0;
    model->n_faces = 0;
    model->n_spaces = 0;
    model->n_triangles = 0;
    model->n_polygons = 0;
}

void n_coords(FILE* file, struct Model* model)
{
    init_model_counters(model);
    char* line = malloc(BUFFER_SIZE);
    int retval = 0;
    regmatch_t rm[2];
    regex_t re,re1,re2,re3,re4,re5,re6;
    if (regcomp(&re, geometric_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", geometric_vertices);
        return ;
    }
    else if (regcomp(&re1, texture_coordinates, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", texture_coordinates);
        return ;
    }
    else if (regcomp(&re2, vertex_normals, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", vertex_normals);
        return ;
    }
    else if (regcomp(&re3, face_elements, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", face_elements);
        return ;
    }
    else if (regcomp(&re4, space_vertices, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", space_vertices);
        return ;
    }
    else if (regcomp(&re5, triangles, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", triangles);
        return ;
    }
   else if (regcomp(&re6, polygons, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Failed to compile regex '%s'\n", polygons);
        return ;
    }
    else
    {
        printf("\nRegex compile completed!\n\n");
    }
    FILE *frp;
    frp=fopen("Vertex_output.txt", "w");
    FILE *frp1;
    frp1=fopen("Texture_output.txt", "w");
    FILE *frp2;
    frp2=fopen("Normal_output.txt", "w");
	while (fgets(line, BUFFER_SIZE, file) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
          fprintf(frp,"%s",line + 2);
          fprintf(frp,"\n");
          model->n_vertices++;
        }
        else if ((retval = regexec(&re1, line, 2, rm, 0)) == 0)
        {
            fprintf(frp1,"%s",line + 2);
            fprintf(frp1,"\n");
	    model->n_texture_vertices++;
        }
        else if ((retval = regexec(&re2, line, 2, rm, 0)) == 0)
        {
	    fprintf(frp2,"%s",line + 2);
            fprintf(frp2,"\n");
            model->n_normals++;
        }
        else if ((retval = regexec(&re3, line, 2, rm, 0)) == 0)
        {
            model->n_faces++;
	    if ((retval = regexec(&re5, line, 2, rm, 0)) == 0)
		{
           	model->n_triangles++;
		}
        	
		else if ((retval = regexec(&re6, line, 2, rm, 0)) == 0)
       		 {	
            	model->n_polygons++;
        	}
       		 }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
           model->n_spaces++;
        }
    }
    fclose (frp);
    fclose (frp1);
    fclose (frp2);
}
void print_model_info(const struct Model* model)
{
    printf("Vertices:\t\t%d\n",model->n_vertices);
    printf("Texture vertices:\t%d\n",model->n_texture_vertices);
    printf("Vertex normals:\t\t%d\n",model->n_normals);
    printf("Face elements:\t\t%d\n",model->n_faces);
    printf("Space vertices:\t\t%d\n\n",model->n_spaces);
    printf("Triangles:\t\t%d\n\n",model->n_triangles);
    printf("Polygons:\t\t%d\n\n",model->n_polygons);
}

void print_bounding_box(struct Model*model,struct Vertex* vertex)
{
    int i=0;
    int j=0;
    double max_x,min_x,max_y,min_y,max_z,min_z;
    FILE *archive;
    archive = fopen("Vertex_output.txt","r");
    if (archive== NULL)
        exit(1);
    while (feof(archive) == 0)
    {
        fscanf(archive, "%lf %lf %lf", &vertex->x[i][0],&vertex->y[i][1],&vertex->z[i][2]);
        for (j=0; j < model->n_vertices ;j++){
        if(vertex->x[i][0] < min_x){
            min_x = vertex->x[i][0];
            }
        else if(vertex->x[i][0] > max_x){
            max_x = vertex->x[i][0];
            }
        if(vertex->y[i][1] < min_y){
            min_y = vertex->y[i][1];
            }
        else if(vertex->y[i][1] > max_y){
            max_y = vertex->y[i][1];
            }
        if(vertex->z[i][2] < min_z){
            min_z = vertex->z[i][2];
            }
        else if(vertex->z[i][2] > max_z){
            max_z = vertex->z[i][2];
            }
        }
    }
    fclose(archive);
    remove("Vertex_output.txt");
    printf("x\t(%lf, %lf)\n", min_x, max_x);
    printf("y\t(%lf, %lf)\n", min_y, max_y);
    printf("z\t(%lf, %lf)\n", min_z, max_z);
    printf("x size =\t%lf\n",max_x-min_x);
    printf("y size =\t%lf\n",max_y-min_y);
    printf("z size =\t%lf\n\n",max_z-min_z);
}
