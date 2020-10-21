#include "value_container.h"

static void test_value_container_empty(void** state)
{
    ValueContainer value_container;
    int count;

    init_value_container(&value_container);
    count = count_values(&value_container);
    assert_int_equal(count, 0);
}

static void test_value_container_create_value(void** state)
{
    ValueContainer value_container;
    Id value_id;
    int count;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "");
    assert_int_equal(value_id, 1);
    count = count_values(&value_container);
    assert_int_equal(count, 1);
    clear_values(&value_container);
}

static void test_value_container_multiple_create_value(void** state)
{
    ValueContainer value_container;
    int count;
    Id i;
    char value[16];

    init_value_container(&value_container);
    for (i = 1; i <= 100; ++i) {
        sprintf(value, "value %lu", i);
        create_value(&value_container, value);
        count = count_values(&value_container);
        assert_int_equal(count, i);
    }
    clear_values(&value_container);
    count = count_values(&value_container);
    assert_int_equal(count, 0);
}

static void test_value_container_destroy_value(void** state)
{
    ValueContainer value_container;
    Id value_id;
    int count;
    Status status;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "");
    status = destroy_value(&value_container, value_id);
    assert_int_equal(status, STATUS_OK);
    count = count_values(&value_container);
    assert_int_equal(count, 0);
}

static void test_value_container_multiple_destroy_value(void** state)
{
    ValueContainer value_container;
    char value[16];
    Id value_id;
    int count;

    init_value_container(&value_container);
    for (value_id = 1; value_id <= 100; ++value_id) {
        sprintf(value, "value %lu", value_id);
        create_value(&value_container, value);
        count = count_values(&value_container);
        assert_int_equal(count, value_id);
    }
    for (value_id = 1; value_id <= 100; ++value_id) {
        destroy_value(&value_container, value_id);
        count = count_values(&value_container);
        assert_int_equal(count, 100 - value_id);
    }
}

static void test_value_container_invalid_destroy_value(void** state)
{
    ValueContainer value_container;
    Status status;
    Id value_id;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "");
    status = destroy_value(&value_container, value_id + 1);
    assert_int_equal(status, STATUS_INVALID_ID);
    clear_values(&value_container);
}

static void test_value_container_get_value(void** state)
{
    ValueContainer value_container;
    Id value_id;
    char* value;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "");
    value = get_value(&value_container, value_id);
    assert_string_equal(value, "");
    clear_values(&value_container);
}

static void test_value_container_multiple_get_value(void** state)
{
    ValueContainer value_container;
    char value[16];
    char* result;
    Id value_id;
    int count;

    init_value_container(&value_container);
    for (value_id = 1; value_id <= 100; ++value_id) {
        sprintf(value, "value %lu", value_id);
        create_value(&value_container, value);
        count = count_values(&value_container);
        assert_int_equal(count, value_id);
    }
    for (value_id = 100; value_id >= 1; --value_id) {
        sprintf(value, "value %lu", value_id);
        result = get_value(&value_container, value_id);
        assert_string_equal(result, value);
    }
    clear_values(&value_container);
}

static void test_value_container_invalid_get_value(void** state)
{
    ValueContainer value_container;
    Id value_id;
    char* value;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "");
    value = get_value(&value_container, value_id + 1);
    assert_ptr_equal(value, NULL);
    clear_values(&value_container);
}

static void test_value_container_interning_simple(void** state)
{
    ValueContainer value_container;
    Id expected_id;
    Id value_id;

    init_value_container(&value_container);
    value_id = create_value(&value_container, "simple");
    expected_id = create_value(&value_container, "simple");
    assert_int_equal(value_id, expected_id);
    clear_values(&value_container);
}

static void test_value_container_interning_multiple(void** state)
{
    ValueContainer value_container;
    char value[16];
    Id value_id;
    int i;
    int j;

    init_value_container(&value_container);
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            sprintf(value, "simple %d", j);
            value_id = create_value(&value_container, value);
            assert_int_equal(value_id, j + 1);
        }
    }
    clear_values(&value_container);
}
