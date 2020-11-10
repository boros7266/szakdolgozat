#include <stdio.h>
#include "vertex.h"


int read_vertex(Vertex* vertex, const char* text)
{
    int i;

    i = 0;
    while (text[i] != 0 && is_numeric(text[i]) == false) {
        ++i;
    }
    if (text[i] != 0) {
        vertex->x = atof(&text[i]);
	printf("vertexx: %lf",vertex->x);
	printf("\n");
    }
    else {
        printf("The x value of vertex is missing!\n");
        return false;
    }
    while (text[i] != 0 && text[i] != ' ') {
        ++i;
    }
    while (text[i] != 0 && is_numeric(text[i]) == false) {
        ++i;
    }
    if (text[i] != 0) {
        vertex->y = atof(&text[i]);
	printf("vertexy: %lf",vertex->y);
	printf("\n");
    }
    else {
        printf("The y value of vertex is missing!\n");
        return false;
    }
    while (text[i] != 0 && text[i] != ' ') {
        ++i;
    }
    while (text[i] != 0 && is_numeric(text[i]) == false) {
        ++i;
    }
    if (text[i] != 0) {
        vertex->z = atof(&text[i]);
	printf("vertexz: %lf",vertex->z);
	printf("\n");
    }
    else {
        printf("The z value of vertex is missing!\n");
        return false;
    }
    return true;
}

