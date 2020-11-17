#include "model.h"

static void test_vertex_line(void** state)
{
    Regular regular;
    char vertex_line[] = "v 1 2 3";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_vertex_line(&regular, vertex_line);
    
    assert_true(result);
}

static void test_texture_vertex_line(void** state)
{
    Regular regular;
    char texture_vertex_line[] = "vt 1 2";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_texture_vertex_line(&regular, texture_vertex_line);
    
    assert_true(result);
}

static void test_vertex_normal_line(void** state)
{
    Regular regular;
    char vertex_normal_line[] = "vn 1 2 3";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_vertex_normal_line(&regular, vertex_normal_line);
    
    assert_true(result);
}

static void test_face_line(void** state)
{
    Regular regular;
    char face_line[] = "f 1 2 3";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_face_line(&regular, face_line);
    
    assert_true(result);
}

static void test_triangle_line(void** state)
{
    Regular regular;
    char triangle_line[] = "f 1/2/3 1/2/3 1/2/3";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_triangle_line(&regular, triangle_line);
    
    assert_true(result);
}

static void test_quad_line(void** state)
{
    Regular regular;
    char quad_line[] = "f 1/2/3 1/2/3 1/2/3 1/2/3";
    bool result;
    
    check_regex_regular_expressions(&regular);
    result = is_quad_line(&regular, quad_line);
    
    assert_true(result);
}
