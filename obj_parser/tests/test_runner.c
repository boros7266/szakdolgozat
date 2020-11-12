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
        cmocka_unit_test(test_vertex_line)
    };
    result = cmocka_run_group_tests(regex_tests, NULL, NULL);
    return result;
}
