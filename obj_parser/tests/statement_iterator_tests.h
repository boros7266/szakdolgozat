#include "statement_iterator.h"

static void test_statement_iterator_init(void** state)
{
    StatementIterator statement_iterator;
    init_iterator(&statement_iterator);
    assert_false(has_next_statement(&statement_iterator));
    assert_null(statement_iterator.items);
    assert_null(statement_iterator.current_item);
    assert_null(statement_iterator.statement);
    release_iterator(&statement_iterator);
}

static void test_statement_iterator_append(void** state)
{
    StatementIterator statement_iterator;
    Statement statement;
    init_iterator(&statement_iterator);
    statement.subject_id = 100;
    statement.predicate_id = 200;
    statement.object_id = 300;
    append_statement(&statement_iterator, &statement);
    assert_false(has_next_statement(&statement_iterator));
    reset_iterator(&statement_iterator);
    assert_int_equal(statement_iterator.statement->subject_id, 100);
    assert_int_equal(statement_iterator.statement->predicate_id, 200);
    assert_int_equal(statement_iterator.statement->object_id, 300);
    assert_false(has_next_statement(&statement_iterator));
    release_iterator(&statement_iterator);
}

static void test_statement_iterator_advance(void** state)
{
    StatementIterator statement_iterator;
    Statement statement;
    int i;
    init_iterator(&statement_iterator);
    for (i = 0; i < 100; ++i) {
        statement.subject_id = 100 + i;
        statement.predicate_id = 200 + i;
        statement.object_id = 300 + i;
        append_statement(&statement_iterator, &statement);
        assert_false(has_next_statement(&statement_iterator));
    }
    reset_iterator(&statement_iterator);
    for (i = 0; i < 100; ++i) {
        assert_int_equal(statement_iterator.statement->subject_id, 100 + i);
        assert_int_equal(statement_iterator.statement->predicate_id, 200 + i);
        assert_int_equal(statement_iterator.statement->object_id, 300 + i);
        if (i < 99) {
            assert_true(has_next_statement(&statement_iterator));
            advance_iterator(&statement_iterator);
        }
        else {
            assert_false(has_next_statement(&statement_iterator));
        }
    }
    release_iterator(&statement_iterator);
}
