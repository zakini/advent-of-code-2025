#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "day1.h"
#include "utils.h"

#define INITIAL_DIAL_POSITION 50
#define NUM_DIAL_POSITIONS 100

struct DialZeroPositionCounts {
    int stoppedOn;
    int passed;
};

struct DialZeroPositionCounts day1(char inputFilePath[]) {
    FILE* file = NULL;
    char* line = NULL;
    size_t buffer_capacity = 0;
    unsigned int line_number = 0;

    int dial_position = INITIAL_DIAL_POSITION;
    int previous_dial_position = INITIAL_DIAL_POSITION;
    int turn_amount = 0;
    struct DialZeroPositionCounts result = {0, 0};

    int temp = 0;

    file = fopen(inputFilePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open %s", inputFilePath);
        exit(EXIT_FAILURE);
    }

    while(getline(&line, &buffer_capacity, file) != -1) {
        previous_dial_position = dial_position;

        if (line[0] == 'L') {
            turn_amount = -strtol(line + sizeof(char), NULL, 10);
        } else if (line[0] == 'R') {
            turn_amount = strtol(line + sizeof(char), NULL, 10);
        } else {
            fprintf(stderr, "Invalid direction on line %d: expected L or R, got %c | full line: %s\n", line_number, line[0], line);
            exit(EXIT_FAILURE);
        }

        // Try to move the dial to 0, if we're not already there
        if (dial_position != 0) {
            if (turn_amount > 0) {
                temp = min(turn_amount, NUM_DIAL_POSITIONS - dial_position);
                dial_position += temp;
                turn_amount -= temp;
            } else if (turn_amount < 0) {
                temp = max(turn_amount, -dial_position);
                dial_position += temp;
                turn_amount -= temp;
            }

            // Wrap 100 back around to 0
            if (dial_position == 100) dial_position = 0;
            // If we're at 0, but still need to turn, then this is a pass of 0
            if (dial_position == 0 && turn_amount != 0) result.passed++;
        }

        // Handle any full rotations remaining
        if (abs(turn_amount) >= NUM_DIAL_POSITIONS) {
            assert(dial_position == 0);

            // Dial is at 0, and would still be on 0 after any number of full rotations, so no need to calculate any of that
            result.passed += abs(turn_amount) / NUM_DIAL_POSITIONS;
            turn_amount %= NUM_DIAL_POSITIONS;

            // If we're done turning, then we just overcounted passes
            if (turn_amount == 0) result.passed--;
        }

        // Add any leftovers
        dial_position += turn_amount;

        // Wrap back around to 0
        if (dial_position < 0) dial_position += NUM_DIAL_POSITIONS;

        // Check if we landed on 0
        if (dial_position == 0) result.stoppedOn++;

        line_number++;
    }

    fclose(file);
    if (line) free(line);

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
