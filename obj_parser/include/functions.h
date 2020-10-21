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


#define geometric_vertices 	"^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*" 		//List of geometric vertices
#define vertex_normals          "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of texture coordinates
#define texture_coordinates     "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //List of vertex normals
#define face_elements           "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //Polygonal face elements
#define space_vertices          "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //Parameter space vertices
#define triangles		"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){3}"		//Parameter triangle
#define quads			"^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*.[0-9]*){4}"		//Parameter quads
#define NrOfFiles 2
#define NrOfFiles2 2

struct timeval start, finish;

void begin();
void OBJ_LOAD();
void texture_count();
void findSize();
void end();

#endif /* FUNCTIONS_H */
