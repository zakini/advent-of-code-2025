#include "day3.h"
#include "utils.h"
#include <assert.h>
// NOLINTNEXTLINE(misc-include-cleaner)
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// NOLINTNEXTLINE(misc-include-cleaner)
#include <sys/types.h>

enum { MAX_DIGIT = 9 };
enum { MAX_BATTERY_BANK_SIZE = 200 };

struct Battery {
  unsigned int joltage;
  unsigned int position;
};

static int parseLine(char *line, struct Battery **bank, size_t *size) {
  size_t line_length = strlen(line);
  assert(line_length > 0);

  *size = line_length;
  *bank = (struct Battery *)malloc(sizeof(struct Battery) * *size);

  for (size_t i = 0; i < *size; i++) {
    (*bank)[i].joltage = (unsigned int)line[i] - '0';
    (*bank)[i].position = (unsigned int)i;

    // Joltage is unsigned, so values less than 0 will underflow and still be
    // caught here
    if (MAX_DIGIT < (*bank)[i].joltage) {
      return -1;
    }
  }

  return 0;
}

// NOLINTNEXTLINE(misc-include-cleaner)
static ssize_t findLargestBatteryIndex(struct Battery *bank, size_t size) {
  ssize_t largestBatteryIndex = -1;

  for (size_t i = 0; i < size; i++) {
    if (largestBatteryIndex == -1 ||
        // NOLINTNEXTLINE(clang-analyzer-security.ArrayBound): pretty sure I'm calculating this offset correctly
        bank[largestBatteryIndex].joltage < bank[i].joltage) {
      largestBatteryIndex = (ssize_t)i;
    }
  }

  return largestBatteryIndex;
}

static long calculateMaxJoltage(struct Battery *bank, size_t size, int batteryCountToUse) {
  ssize_t temp = -1;
  size_t largest_battery_indexes[MAX_BATTERY_BANK_SIZE] = {};
  char max_bank_joltage[MAX_BATTERY_BANK_SIZE + 1] = "";
  long max_joltage = -1;

  for (int i = 0; i < batteryCountToUse; i++) {
    if (i == 0) {
      temp = findLargestBatteryIndex(bank, size - (size_t)(batteryCountToUse - 1));
      exit_if(temp < 0, "Failed to find largest battery\n");
    } else {
      temp = findLargestBatteryIndex(&bank[largest_battery_indexes[i - 1] + 1],
                                     size - largest_battery_indexes[i - 1] - (size_t)(batteryCountToUse - i));
      exit_if(temp < 0, "Failed to find largest battery\n");
      temp += (ssize_t)largest_battery_indexes[i - 1] + 1;
    }

    largest_battery_indexes[i] = (size_t)temp;
    max_bank_joltage[i] = (char)(bank[largest_battery_indexes[i]].joltage + '0');
  }


  max_joltage = strtol(max_bank_joltage, NULL, DECIMAL_BASE);
  assert(0 <= max_joltage && max_joltage <= (pow(10, batteryCountToUse) - 1));
  return max_joltage;
}

static long day3(char *inputFilePath, int batteryCountToUse) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length = 0;
  unsigned int line_number = 0;

  struct Battery *battery_bank = NULL;
  size_t battery_bank_size = 0;
  long result = 0;

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while ((line_length = getline(&line, &line_capacity, file)) != -1) {
    line = trim(line);
    exit_if(line_length <= 1, "Line %u is empty\n", line_number);
    exit_if(parseLine(line, &battery_bank, &battery_bank_size) == -1,
            "Line %u contains a joltage that is not a digit | full line: %s\n",
            line_number, line);

    result += calculateMaxJoltage(battery_bank, battery_bank_size, batteryCountToUse);

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

long day3Part1(char *inputFilePath) {
  return day3(inputFilePath, 2);
}

long day3Part2(char *inputFilePath) {
  // NOLINTNEXTLINE(readability-magic-numbers)
  return day3(inputFilePath, 12);
}
