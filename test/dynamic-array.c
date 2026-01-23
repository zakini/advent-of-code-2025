#include "dynamic-array.h"
#include "../src/dynamic-array.h"
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdio.h>
#include <stdlib.h>

enum { DA_CHUNK_SIZE = 100 };

static void it_can_allocate_and_free_empty_dynamic_array(void) {
  struct DynamicArray *array = NULL;

  DA_alloc(&array);
  CU_ASSERT_PTR_NOT_NULL(array);

  DA_free(&array);
  CU_ASSERT_PTR_NULL(array);
}

static void it_returns_null_pointer_when_getting_unused_index(void) {
  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  CU_ASSERT_PTR_NULL(DA_get(array, 42));

  DA_free(&array);
}

static void it_returns_zero_length_for_empty_array(void) {
  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  CU_ASSERT_EQUAL(DA_len(array), 0);

  DA_free(&array);
}

static void it_can_push_a_long(void) {
  long *value = (long*)malloc(sizeof(long));
  *value = 42;

  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  DA_push(array, value);

  CU_ASSERT_EQUAL(DA_len(array), 1);
  CU_ASSERT_EQUAL(*(long*)DA_get(array, 0), *value);

  DA_free(&array);
}

static void it_can_push_longs_up_to_allocated_amount(void) {
  long *value = NULL;
  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  for (long i = 0; i < DA_CHUNK_SIZE; i++) {
    value = (long*)malloc(sizeof(long));
    *value = i;
    DA_push(array, value);
  }

  CU_ASSERT_EQUAL(DA_len(array), DA_CHUNK_SIZE);

  for (long i = 0; i < DA_CHUNK_SIZE; i++) {
    CU_ASSERT_EQUAL(*(long*)DA_get(array, (size_t)i), i);
  }

  DA_free(&array);
}

static void it_can_push_longs_past_allocated_amount(void) {
  long *value = NULL;
  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  for (long i = 0; i < DA_CHUNK_SIZE * 5L; i++) {
    value = (long*)malloc(sizeof(long));
    *value = i;
    DA_push(array, value);
  }

  CU_ASSERT_EQUAL(DA_len(array), DA_CHUNK_SIZE * 5L);

  for (long i = 0; i < DA_CHUNK_SIZE * 5L; i++) {
    value = (long*)DA_get(array, (size_t)i);
    CU_ASSERT_EQUAL(*value, i);
  }

  DA_free(&array);
}

static void it_can_clear(void) {
  long *value = NULL;
  struct DynamicArray *array = NULL;
  DA_alloc(&array);

  for (long i = 0; i < DA_CHUNK_SIZE; i++) {
    value = (long*)malloc(sizeof(long));
    *value = i;
    DA_push(array, value);
  }

  CU_ASSERT_EQUAL(DA_len(array), DA_CHUNK_SIZE);

  DA_clear(array);

  CU_ASSERT_EQUAL(DA_len(array), 0);

  DA_free(&array);
}

int createDynamicArraysTestSuite(void) {
  CU_pSuite suite = NULL;

  suite = CU_add_suite("Dynamic Arrays", NULL, NULL);
  if (suite == NULL) {
    return EXIT_FAILURE;
  }

  CU_ADD_TEST(suite, it_can_allocate_and_free_empty_dynamic_array);
  CU_ADD_TEST(suite, it_returns_null_pointer_when_getting_unused_index);
  CU_ADD_TEST(suite, it_returns_zero_length_for_empty_array);
  CU_ADD_TEST(suite, it_can_push_a_long);
  CU_ADD_TEST(suite, it_can_push_longs_up_to_allocated_amount);
  CU_ADD_TEST(suite, it_can_push_longs_past_allocated_amount);
  CU_ADD_TEST(suite, it_can_clear);

  return EXIT_SUCCESS;
}
