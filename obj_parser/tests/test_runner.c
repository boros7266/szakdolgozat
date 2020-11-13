#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdbool.h>
#include <stdio.h>

#include "regex_tests.h"

int main(int argc, char* argv[])
{
    int result;
    const struct CMUnitTest regex_tests[] = {
        cmocka_unit_test(test_vertex_line),
	cmocka_unit_test(test_texture_vertex_line),
	cmocka_unit_test(test_vertex_normal_line),
	cmocka_unit_test(test_face_line),
	cmocka_unit_test(test_triangle_line),
	cmocka_unit_test(test_quad_line)
    };
    result = cmocka_run_group_tests(regex_tests, NULL, NULL);
    return result;
}
