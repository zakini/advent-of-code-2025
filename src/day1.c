#include "day1.h"
#include "utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { INITIAL_DIAL_POSITION = 50, NUM_DIAL_POSITIONS = 100 };

struct DialZeroPositionCounts {
  int stoppedOn;
  int passed;
};

static int parseLine(const char *line, unsigned int line_number) {
  exit_if(strlen(line) < 2, "Line %u is too short | full line: %s\n", line_number, line);

  if (line[0] == 'L') {
    return -(int)strtol(line + sizeof(char), NULL, DECIMAL_BASE);
  }
  if (line[0] == 'R') {
    return (int)strtol(line + sizeof(char), NULL, DECIMAL_BASE);
  }

  exit_if(true, "Invalid direction on line %u: expected L or R, got %c | full "
          "line: %s\n",
          line_number, line[0], line);
}

static void rotateDialTowardsZero(int *dial_position, int *turn_amount,
                                  struct DialZeroPositionCounts *result) {
  int temp = 0;

  if (*dial_position != 0) {
    if (*turn_amount > 0) {
      temp = min(*turn_amount, NUM_DIAL_POSITIONS - *dial_position);
      *dial_position += temp;
      *turn_amount -= temp;
    } else if (*turn_amount < 0) {
      temp = max(*turn_amount, -*dial_position);
      *dial_position += temp;
      *turn_amount -= temp;
    }

    // Wrap 100 back around to 0
    if (*dial_position == NUM_DIAL_POSITIONS) {
      *dial_position = 0;
    }
    // If we're at 0, but still need to turn, then this is a pass of 0
    if (*dial_position == 0 && *turn_amount != 0) {
      (*result).passed++;
    }
  }
}

// NOLINTNEXTLINE(clang-diagnostic-unused-parameter,misc-unused-parameters,bugprone-easily-swappable-parameters) it... _is_ used?? and cba dealing with making these int pointers opaque
static void applyFullRotations(int *dial_position, int *turn_amount,
                               struct DialZeroPositionCounts *result) {
  if (abs(*turn_amount) >= NUM_DIAL_POSITIONS) {
    assert((*dial_position) == 0);

    // Dial is at 0, and would still be on 0 after any number of full
    // rotations, so no need to calculate any of that
    (*result).passed += abs(*turn_amount) / NUM_DIAL_POSITIONS;
    *turn_amount %= NUM_DIAL_POSITIONS;

    // If we're done turning, then we just overcounted passes
    if (*turn_amount == 0) {
      (*result).passed--;
    }
  }
}

static struct DialZeroPositionCounts day1(char inputFilePath[]) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  unsigned int line_number = 0;

  int dial_position = INITIAL_DIAL_POSITION;
  int turn_amount = 0;
  struct DialZeroPositionCounts result = {0, 0};

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while (getline(&line, &line_capacity, file) != -1) {
    turn_amount = parseLine(line, line_number);

    rotateDialTowardsZero(&dial_position, &turn_amount, &result);
    applyFullRotations(&dial_position, &turn_amount, &result);

    // Add any leftovers
    dial_position += turn_amount;

    // Wrap back around to 0
    if (dial_position < 0) {
      dial_position += NUM_DIAL_POSITIONS;
    }

    // Check if we landed on 0
    if (dial_position == 0) {
      result.stoppedOn++;
    }

    line_number++;
  }

  if (line != NULL) {
    free(line);
  }

  exit_if(fclose(file) != 0, "Failed to close file handle\n");

  return result;
}

int day1Part1(char inputFilePath[]) {
  struct DialZeroPositionCounts result;

  result = day1(inputFilePath);

  return result.stoppedOn;
}

int day1Part2(char inputFilePath[]) {
  struct DialZeroPositionCounts result;

  result = day1(inputFilePath);

  return result.stoppedOn + result.passed;
}
