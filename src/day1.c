#include "day1.h"
#include "utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum { INITIAL_DIAL_POSITION = 50, NUM_DIAL_POSITIONS = 100 };
enum { DECIMAL_BASE = 10 };
enum { MAX_INPUT_FILE_LINE_LENGTH = 8 };

struct DialZeroPositionCounts {
  int stoppedOn;
  int passed;
};

int parseLine(const char *line, unsigned int line_number) {
  if (line[0] == 'L') {
    return -(int)strtol(line + sizeof(char), NULL, DECIMAL_BASE);
  }
  if (line[0] == 'R') {
    return (int)strtol(line + sizeof(char), NULL, DECIMAL_BASE);
  }

  // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
  fprintf(stderr,
          "Invalid direction on line %d: expected L or R, got %c | full "
          "line: %s\n",
          line_number, line[0], line);
  exit(EXIT_FAILURE);
}

void rotateDialTowardsZero(int *dial_position, int *turn_amount,
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

// NOLINTNEXTLINE(misc-unused-parameters,bugprone-easily-swappable-parameters) it... _is_ used?? and cba dealing with making these int pointers opaque
void applyFullRotations(int *dial_position, int *turn_amount,
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

struct DialZeroPositionCounts day1(char inputFilePath[]) {
  FILE *file = NULL;
  char line[MAX_INPUT_FILE_LINE_LENGTH];
  unsigned int line_number = 0;

  int dial_position = INITIAL_DIAL_POSITION;
  int turn_amount = 0;
  struct DialZeroPositionCounts result = {0, 0};

  file = fopen(inputFilePath, "r");
  if (file == NULL) {
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to open %s", inputFilePath);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), file) != NULL) {
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

  if (fclose(file) != 0) {
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to close file handle");
    exit(EXIT_FAILURE);
  }

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
