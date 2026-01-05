#ifndef AOC25_SRC_DYNAMIC_ARRAY_H
#define AOC25_SRC_DYNAMIC_ARRAY_H

#include <stddef.h>

struct DynamicArray;

void DA_alloc(struct DynamicArray **array);
void DA_free(struct DynamicArray *array);

long DA_get(struct DynamicArray *array, size_t index);
size_t DA_len(struct DynamicArray *array);

void DA_push(struct DynamicArray *array, long value);
void DA_clear(struct DynamicArray *array);

void DA_debug(struct DynamicArray *array);

#endif
