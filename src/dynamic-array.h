#ifndef AOC25_SRC_DYNAMIC_ARRAY_H
#define AOC25_SRC_DYNAMIC_ARRAY_H

#include <stddef.h>

struct DynamicArray;

void DA_alloc(struct DynamicArray **array);
void DA_free(struct DynamicArray **array);

void *DA_get(struct DynamicArray *array, size_t index);
size_t DA_len(struct DynamicArray *array);

void DA_push(struct DynamicArray *array, void *value);
void DA_clear(struct DynamicArray *array);

void DA_debug(struct DynamicArray *array, void *printValue(size_t, void *));

#endif
