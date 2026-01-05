#include "day2.h"
#include "dynamic-array.h"
#include "utils.h"
#include <float.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
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

static long day2(char inputFilePath[], size_t maxSegments) {
  FILE *file = NULL;
  char *input_value = NULL;
  size_t input_capacity = 0;
  unsigned int input_number = 0;

  struct Range current_range = {0, 0};
  char string_value[BUFFER_MAX] = "";
  unsigned long max_segments_for_value = 0;
  char value_segments[BUFFER_MAX][BUFFER_MAX] = {};
  bool all_same = false;
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

    for (long value = current_range.start; value <= current_range.end; value++) {
      sprintf(string_value, "%ld", value);
      max_segments_for_value = min(maxSegments, strlen(string_value));

      for (size_t segment_count = 2; segment_count <= max_segments_for_value; segment_count++) {
        // Check if we can split this string into the current number of segments
        if (strlen(string_value) % segment_count != 0) {
          continue;
        }

        for (size_t i = 0; i < segment_count; i++) {
          strncpy(value_segments[i],
                  string_value + (i * sizeof(char) * strlen(string_value) / segment_count),
                  strlen(string_value));
          value_segments[i][strlen(string_value) / segment_count] = 0;
        }

        all_same = true;
        for (size_t i = 0; i < segment_count - 1; i++) {
          if (strcmp(value_segments[i], value_segments[i+1]) != 0) {
            all_same = false;
            break;
          }
        }


        if (all_same) {
          DA_push(invalid_ids, value);
          break;
        }
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

long day2Part1(char inputFilePath[]) {
  return day2(inputFilePath, 2);
}

long day2Part2(char inputFilePath[]) {
  return day2(inputFilePath, SIZE_MAX);
}
