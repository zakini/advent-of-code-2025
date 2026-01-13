#include "day3.h"
#include "utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BATTERY_BANK_SIZE 200

struct Battery {
  unsigned int joltage;
  unsigned int position;
};

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

long day3Part1(char *inputFilePath) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length = 0;
  unsigned int line_number = 0;

  struct Battery battery_bank[MAX_BATTERY_BANK_SIZE] = {};
  size_t battery_bank_size = 0;
  ssize_t temp = -1;
  size_t largest_battery_indexes[2] = {};
  char max_bank_joltage[2] = "";
  int result = 0;

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while ((line_length = getline(&line, &line_capacity, file)) != -1) {
    exit_if(line_length <= 1, "Line %u is empty\n", line_number);

    for (ssize_t i = 0; i < line_length - 1; i++) {
      battery_bank[i].joltage = (unsigned int)line[i] - '0';
      battery_bank[i].position = (unsigned int)i;
      exit_if(battery_bank[i].joltage < 0 || 9 < battery_bank[i].joltage, "Battery joltage at %u:%ld is not a digit | full line: %s\n", line_number, i, line);
    }

    battery_bank_size = (size_t)line_length - 1;

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

  return result;
}
