#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <regex.h>
#include <unistd.h>
#include <SOIL/SOIL.h>
#include <GL/glut.h>

#define geometric_vertices 	"^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*" 		//List of geometric vertices
#define vertex_normals          "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of texture coordinates
#define texture_coordinates     "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of vertex normals
#define face_elements           "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //Polygonal face elements
#define space_vertices          "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //Parameter space vertices
#define triangles		"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){3}[\\ ]*$"		//Parameter triangle
#define quads			"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){4}[\\ ]*"		//Parameter quads
#define picture1		"^.*.png"
#define picture2		"^.*.jpg"
#define NrOfFiles 6
#define NrOfFiles2 1

struct timeval start, finish;

typedef GLubyte Pixel[3];

struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_faces;
    int n_space;
    int n_triangles;
    int n_quads;
};

void begin();
void OBJ_LOAD();
void texture_count();
void findSize();
void end();

#endif /* FUNCTIONS_H */
