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
  long *data;
};

void DA_alloc(struct DynamicArray **array) {
  *array = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
  (*array)->occupied = 0;
  (*array)->allocated = ALLOC_CHUNK_SIZE;
  (*array)->data = (long *)malloc(ALLOC_CHUNK_SIZE * sizeof(long));
}

static void DA_expand(struct DynamicArray *array) {
  long *temp = NULL;

  assert(array->occupied <= array->allocated);

  if (array->occupied >= array->allocated) {
    temp = (long *)realloc(array->data, (array->allocated + ALLOC_CHUNK_SIZE) * sizeof(long));
    exit_if(temp == NULL, "Failed to expand dynamic array");
    array->data = temp;
    array->allocated += ALLOC_CHUNK_SIZE;
  }
}

void DA_free(struct DynamicArray *array) {
  free(array->data);
  free(array);
}

long DA_get(struct DynamicArray *array, size_t index) {
  return array->data[index];
}

size_t DA_len(struct DynamicArray *array) { return array->occupied; }

void DA_push(struct DynamicArray *array, long value) {
  DA_expand(array);
  array->data[array->occupied] = value;
  array->occupied++;
}

void DA_clear(struct DynamicArray *array) { array->occupied = 0; }

void DA_debug(struct DynamicArray *array) {
  printf("Dynamic array - occupied: %zu, allocated: %zu\nContents:\n\n",
         array->occupied, array->allocated);
  for (size_t i = 0; i < array->occupied; i++) {
    printf("%lu: %ld\n", i, array->data[i]);
  }
}
