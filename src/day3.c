#include "day3.h"
#include "utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_DIGIT = 9 };

struct Battery {
  unsigned int joltage;
  unsigned int position;
};

static int parseLine(char *line, struct Battery **bank, size_t *size) {
  size_t line_length = strlen(line);
  assert(line_length > 0);

  // TODO use trim instead
  *size = line_length - 1;
  *bank = (struct Battery *)malloc(sizeof(struct Battery) * *size);

  for (size_t i = 0; i < *size; i++) {
    (*bank)[i].joltage = (unsigned int)line[i] - '0';
    (*bank)[i].position = (unsigned int)i;

    // Joltage is unsigned, so values less than 0 will underflow and still be caught here
    if (MAX_DIGIT < (*bank)[i].joltage) {
      return -1;
    }
  }

  return 0;
}

static ssize_t findLargestBatteryIndex(struct Battery *bank, size_t size) {
  ssize_t largestBatteryIndex = -1;

  for (size_t i = 0; i < size; i++) {
    if (largestBatteryIndex == -1 ||
        bank[largestBatteryIndex].joltage < bank[i].joltage) {
      largestBatteryIndex = (ssize_t)i;
    }
  }

  return largestBatteryIndex;
}

static int calculateMaxJoltage(struct Battery *bank, size_t size) {
  ssize_t temp = -1;
  size_t largest_battery_indexes[2] = {};
  char max_bank_joltage[2 + 1] = "";
  int max_joltage = -1;

  temp = findLargestBatteryIndex(bank, size - 1);
  exit_if(temp < 0, "Failed to find largest battery\n");
  largest_battery_indexes[0] = (size_t)temp;
  temp = findLargestBatteryIndex(&bank[largest_battery_indexes[0] + 1], size - largest_battery_indexes[0] - 1);
  exit_if(temp < 0, "Failed to find second largest battery\n");
  largest_battery_indexes[1] = (size_t)temp + largest_battery_indexes[0] + 1;

  max_bank_joltage[0] = (char)(bank[largest_battery_indexes[0]].joltage + '0');
  max_bank_joltage[1] = (char)(bank[largest_battery_indexes[1]].joltage + '0');

  max_joltage = (int)strtol(max_bank_joltage, NULL, DECIMAL_BASE);
  assert(0 <= max_joltage && max_joltage <= 99);
  return max_joltage;
}

long day3Part1(char *inputFilePath) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length = 0;
  unsigned int line_number = 0;

  struct Battery *battery_bank = NULL;
  size_t battery_bank_size = 0;
  ssize_t temp = -1;
  size_t largest_battery_indexes[2] = {};
  char max_bank_joltage[2] = "";
  int result = 0;

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while ((line_length = getline(&line, &line_capacity, file)) != -1) {
    exit_if(line_length <= 1, "Line %u is empty\n", line_number);
    exit_if(parseLine(line, &battery_bank, &battery_bank_size) == -1, "Line %u contains a joltage that is not a digit | full line: %s\n", line_number, line);

    temp = findLargestBatteryIndex(battery_bank, battery_bank_size - 1);
    exit_if(temp < 0, "Failed to find largest battery\n");
    largest_battery_indexes[0] = (size_t)temp;
    temp = findLargestBatteryIndex(&battery_bank[largest_battery_indexes[0] + 1], battery_bank_size - largest_battery_indexes[0] - 1);
    exit_if(temp < 0, "Failed to find second largest battery\n");
    largest_battery_indexes[1] = (size_t)temp + largest_battery_indexes[0] + 1;

    max_bank_joltage[0] = (char)(battery_bank[largest_battery_indexes[0]].joltage + '0');
    max_bank_joltage[1] = (char)(battery_bank[largest_battery_indexes[1]].joltage + '0');

    result += (int)strtol(max_bank_joltage, NULL, DECIMAL_BASE);

    line_number++;
  }

  exit_if(fclose(file) != 0, "Failed to close file handle\n");

  if (line != NULL) {
    free(line);
  }

  if (battery_bank != NULL) {
    free(battery_bank);
  }

  return result;
}
