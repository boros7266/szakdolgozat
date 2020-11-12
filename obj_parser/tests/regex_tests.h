#include "model.h"

static void test_vertex_line(void** state)
{
    Regular regular;
    char vertex_line[] = "v 1 2 3";
    bool result;
    
    regex_check(&regular);
    result = is_vertex_line(&regular, vertex_line);
    
    assert_true(result);
}
