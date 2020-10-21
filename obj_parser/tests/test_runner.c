#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdbool.h>
#include <stdio.h>

#include "value_container_tests.h"
#include "statement_iterator_tests.h"
#include "graph_tests.h"

int main(int argc, char* argv[])
{
    int result;
    const struct CMUnitTest value_container_tests[] = {
        cmocka_unit_test(test_value_container_empty),
        cmocka_unit_test(test_value_container_create_value),
        cmocka_unit_test(test_value_container_multiple_create_value),
        cmocka_unit_test(test_value_container_destroy_value),
        cmocka_unit_test(test_value_container_multiple_destroy_value),
        cmocka_unit_test(test_value_container_invalid_destroy_value),
        cmocka_unit_test(test_value_container_get_value),
        cmocka_unit_test(test_value_container_multiple_get_value),
        cmocka_unit_test(test_value_container_invalid_get_value),
        cmocka_unit_test(test_value_container_interning_simple),
        cmocka_unit_test(test_value_container_interning_multiple)
    };
    const struct CMUnitTest statement_iterator_tests[] = {
        cmocka_unit_test(test_statement_iterator_init),
        cmocka_unit_test(test_statement_iterator_append),
        cmocka_unit_test(test_statement_iterator_advance)
    };
    const struct CMUnitTest graph_tests[] = {
        cmocka_unit_test(test_graph_init),
        cmocka_unit_test(test_graph_simple_statement_from_ids),
        cmocka_unit_test(test_graph_simple_statement_from_values),
        cmocka_unit_test(test_graph_multiple_statements),
        cmocka_unit_test(test_graph_destroy_node),
        cmocka_unit_test(test_graph_destroy_missing_node),
        cmocka_unit_test(test_graph_destroy_joined_node),
        cmocka_unit_test(test_graph_destroy_statement),
        cmocka_unit_test(test_graph_destroy_missing_statement),
        cmocka_unit_test(test_graph_empty_save_and_load)
    };
    result = cmocka_run_group_tests(value_container_tests, NULL, NULL);
    result = cmocka_run_group_tests(statement_iterator_tests, NULL, NULL);
    result = cmocka_run_group_tests(graph_tests, NULL, NULL);
    return result;
}
