#include "quad.h"

#include <stdio.h>

int read_quad(Quad* quad, const char* text)
{
    int point_index;
    int i;

    i = 0;
    for (point_index = 0; point_index < 4; ++point_index) {
        while (text[i] != 0 && is_numeric(text[i]) == false) {
            ++i;
        }
        if (text[i] != 0) {
            quad->points[point_index].vertex_index = atoi(&text[i]);
        }
        else {
            printf("The vertex index of the %d. points is missing!\n", point_index + 1);
            return false;
        }
        while (text[i] != 0 && text[i] != '/') {
            ++i;
        }
        ++i;
        if (text[i] != 0) {
            quad->points[point_index].texture_index = atoi(&text[i]);
        }
        else {
            printf("The texture index of the %d. points is missing!\n", point_index + 1);
            return false;
        }
        while (text[i] != 0 && text[i] != '/') {
            ++i;
        }
        ++i;
        if (text[i] != 0) {
            quad->points[point_index].normal_index = atoi(&text[i]);
        }
        else {
            printf("The normal index of the %d. points is missing!\n", point_index + 1);
            return false;
        }
        while (text[i] != 0 && text[i] != ' ') {
            ++i;
        }
    }
    return true;
}
