#include "graph.h"

static void test_graph_init(void** state)
{
    Graph graph;
    init_graph(&graph);
    assert_null(graph.statements);
    assert_null(graph.value_container.values);
    assert_int_equal(count_nodes(&graph), 0);
    assert_int_equal(count_statements(&graph), 0);
    release_graph(&graph);
}

static void test_graph_simple_statement_from_ids(void** state)
{
    Graph graph;
    Statement statement;
    Status status;

    init_graph(&graph);
    statement.subject_id = create_node(&graph, "subject");
    statement.predicate_id = create_node(&graph, "predicate");
    statement.object_id = create_node(&graph, "object");
    assert_int_equal(count_nodes(&graph), 3);
    status = create_statement(&graph, &statement);
    assert_int_equal(status, STATUS_OK);
    assert_int_equal(count_statements(&graph), 1);
    assert_true(has_predicate_by_id(&graph, statement.subject_id, statement.predicate_id));
    release_graph(&graph);
}

static void test_graph_simple_statement_from_values(void** state)
{
    Graph graph;
    Status status;
    Id node_id;

    init_graph(&graph);
    status = create_statement_from_values(&graph, "subject", "predicate", "object");
    assert_int_equal(status, STATUS_OK);
    assert_int_equal(count_nodes(&graph), 3);
    assert_int_equal(count_statements(&graph), 1);
    node_id = find_node_id(&graph, "subject");
    assert_true(has_predicate(&graph, node_id, "predicate"));
    release_graph(&graph);
}

static void test_graph_multiple_statements(void** state)
{
    Graph graph;
    Status status;
    char value[16];
    int i;

    init_graph(&graph);
    for (i = 0; i < 10; ++i) {
        sprintf(value, "$predicate %d", i);
        status = create_statement_from_values(&graph, "@1", value, "@2");
        assert_int_equal(status, STATUS_OK);
    }
    assert_int_equal(count_nodes(&graph), 12);
    assert_int_equal(count_statements(&graph), 10);
    for (i = 0; i < 10; ++i) {
        sprintf(value, "$predicate %d", i);
        assert_true(has_predicate_by_values(&graph, "@1", value));
    }
    release_graph(&graph);
}

static void test_graph_destroy_node(void** state)
{
    Graph graph;
    Id node_id;
    Status status;

    init_graph(&graph);
    node_id = create_node(&graph, "@1");
    assert_int_equal(find_node_id(&graph, "@1"), node_id);
    status = destroy_node(&graph, node_id);
    assert_int_equal(status, STATUS_OK);
    assert_int_equal(find_node_id(&graph, "@1"), 0);
    assert_int_equal(count_nodes(&graph), 0);
    release_graph(&graph);
}

static void test_graph_destroy_missing_node(void** state)
{
    Graph graph;
    Status status;

    init_graph(&graph);
    create_statement_from_values(&graph, "@1", "$predicate", "@2");
    find_node_id(&graph, "@1");
    status = destroy_node(&graph, 4);
    assert_int_equal(status, STATUS_INVALID_ID);
    assert_int_equal(count_nodes(&graph), 3);
    release_graph(&graph);
}

static void test_graph_destroy_joined_node(void** state)
{
    Graph graph;
    Id node_id;
    Status status;

    init_graph(&graph);
    create_statement_from_values(&graph, "@1", "$predicate", "@2");
    node_id = find_node_id(&graph, "@1");
    status = destroy_node(&graph, node_id);
    assert_int_equal(status, STATUS_INTEGRITY_ERROR);
    node_id = find_node_id(&graph, "$predicate");
    status = destroy_node(&graph, node_id);
    assert_int_equal(status, STATUS_INTEGRITY_ERROR);
    node_id = find_node_id(&graph, "@2");
    status = destroy_node(&graph, node_id);
    assert_int_equal(status, STATUS_INTEGRITY_ERROR);
    assert_int_equal(count_nodes(&graph), 3);
    assert_int_equal(count_statements(&graph), 1);
    release_graph(&graph);
}

static void test_graph_destroy_statement(void** state)
{
    Graph graph;
    Status status;

    init_graph(&graph);
    status = create_statement_from_values(&graph, "@1", "$predicate", "@2");
    assert_int_equal(status, STATUS_OK);
    assert_int_equal(count_nodes(&graph), 3);
    assert_int_equal(count_statements(&graph), 1);
    status = destroy_statement_by_values(&graph, "@1", "$predicate", "@2");
    assert_int_equal(status, STATUS_OK);
    assert_int_equal(count_nodes(&graph), 3);
    assert_int_equal(count_statements(&graph), 0);
    release_graph(&graph);
}

static void test_graph_destroy_missing_statement(void** state)
{
    Graph graph;
    Status status;

    init_graph(&graph);
    status = create_statement_from_values(&graph, "@1", "$predicate", "@2");
    status = destroy_statement_by_values(&graph, "@1", "$invalid", "@2");
    assert_int_equal(status, STATUS_MISSING_STATEMENT);
    assert_int_equal(count_nodes(&graph), 3);
    assert_int_equal(count_statements(&graph), 1);
    release_graph(&graph);
}

static void test_graph_empty_save_and_load(void** state)
{
    Graph graph;

    init_graph(&graph);
    save_graph(&graph, "/tmp/test.graph");
    load_graph(&graph, "/tmp/test.graph");
    assert_null(graph.statements);
    assert_null(graph.value_container.values);
    release_graph(&graph);
}

/* TODO: Write more test cases for graph saving and loading! */
