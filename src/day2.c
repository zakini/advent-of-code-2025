#include "day2.h"
#include "dynamic-array.h"
#include "utils.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BUFFER_MAX = 100 };

struct Range {
  long start;
  long end;
};

static struct Range parseValue(char *value, unsigned int input_number) {
  char full_value[BUFFER_MAX] = "";
  struct Range range = {0, 0};
  char *next_value = NULL;

  exit_if(strlen(value) > 100,
          "Value %u is too long to parse | full value: %s\n", input_number,
          value);
  strncpy(full_value, value, min(strlen(value), 100 - 1));

  next_value = strtok(value, "-");
  exit_if(next_value == NULL,
          "Failed to parse value %u: missing range start | full value: %s\n",
          input_number, full_value);
  range.start = strtol(next_value, NULL, DECIMAL_BASE);

  next_value = strtok(NULL, "-");
  exit_if(next_value == NULL,
          "Failed to parse value %u: missing range end | full value: %s\n",
          input_number, full_value);
  range.end = strtol(next_value, NULL, DECIMAL_BASE);

  next_value = strtok(NULL, "-");
  exit_if(next_value != NULL,
          "Failed to parse value %u: extra input at end | full value: %s\n",
          input_number, full_value);

  return range;
}

long day2Part1(char *inputFilePath) {
  FILE *file = NULL;
  char *input_value = NULL;
  size_t input_capacity = 0;
  unsigned int input_number = 0;

  struct Range current_range = {0, 0};
  char string_value[BUFFER_MAX] = "";
  char first_half[BUFFER_MAX] = "";
  char second_half[BUFFER_MAX] = "";
  struct DynamicArray *invalid_ids = NULL;
  long result = 0;

  DA_alloc(&invalid_ids);

  file = fopen(inputFilePath, "r");
  if (file == NULL) {
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to open %s\n", inputFilePath);
    DA_free(invalid_ids);
    exit(EXIT_FAILURE);
  }

  while (getdelim(&input_value, &input_capacity, ',', file) != -1) {
    current_range = parseValue(input_value, input_number);

    for (long i = current_range.start; i <= current_range.end; i++) {
      sprintf(string_value, "%ld", i);

      // Odd number of digits in this ID, so impossible for it to only be made
      // of 2 sets of a sequence of digits
      if (strlen(string_value) % 2 != 0) {
        continue;
      }

      strncpy(first_half, string_value, strlen(string_value));
      first_half[strlen(string_value) / 2] = 0;
      strncpy(second_half,
              string_value + (sizeof(char) * strlen(string_value) / 2),
              strlen(string_value));

      if (strcmp(first_half, second_half) == 0) {
        DA_push(invalid_ids, i);
      }
    }

    for (size_t i = 0; i < DA_len(invalid_ids); i++) {
      result += DA_get(invalid_ids, i);
    }

    DA_clear(invalid_ids);

    input_number++;
  }

  DA_free(invalid_ids);

  if (input_value != NULL) {
    free(input_value);
  }

  exit_if(fclose(file) != 0, "Failed to close file handle\n");

  return result;
}
