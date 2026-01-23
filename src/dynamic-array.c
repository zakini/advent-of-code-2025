#include "dynamic-array.h"
#include "utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum { ALLOC_CHUNK_SIZE = 100 };

struct DynamicArray {
  size_t occupied;
  size_t allocated;
  void **data;
};

void DA_alloc(struct DynamicArray **array) {
  *array = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
  (*array)->occupied = 0;
  (*array)->allocated = ALLOC_CHUNK_SIZE;
  (*array)->data = (void**)malloc(ALLOC_CHUNK_SIZE * sizeof(void*));
  exit_if((*array)->data == NULL, "Failed to allocate memory for dynamic array\n");
}

static void DA_expand(struct DynamicArray *array) {
  void *temp = NULL;

  assert(array->occupied <= array->allocated);

  if (array->occupied >= array->allocated) {
    temp = realloc((void*)array->data, (array->allocated + ALLOC_CHUNK_SIZE) *
                                            sizeof(void*));
    exit_if(temp == NULL, "Failed to expand dynamic array");
    array->data = (void**)temp;
    array->allocated += ALLOC_CHUNK_SIZE;
  }
}

void DA_free(struct DynamicArray **array) {
  DA_clear(*array);
  free((void*)(*array)->data);
  free(*array);
  *array = NULL;
}

void* DA_get(struct DynamicArray *array, size_t index) {
  return array->data[index];
}

size_t DA_len(struct DynamicArray *array) { return array->occupied; }

void DA_push(struct DynamicArray *array, void *value) {
  DA_expand(array);
  array->data[array->occupied] = value;
  array->occupied++;
}

void DA_clear(struct DynamicArray *array) {
  for (size_t i = 0; i < array->occupied; i++) {
    free(array->data[i]);
  }

  array->occupied = 0;
}

void DA_debug(struct DynamicArray *array, void *printValue(void *)) {
  printf("Dynamic array - occupied: %zu, allocated: %zu\nContents:\n\n",
         array->occupied, array->allocated);

  for (size_t i = 0; i < array->occupied; i++) {
    printValue(array->data[i]);
  }
}
