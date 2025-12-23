#include <stdio.h>
#include <stdlib.h>
#include "day1.h"

#define INITIAL_DIAL_POSITION 50;
#define NUM_DIAL_POSITIONS 100;

int day1(char inputFilePath[]) {
    FILE* file = NULL;
    char* line = NULL;
    size_t buffer_capacity = 0;
    ssize_t line_length = 0;
    unsigned int line_number = 0;

    int dial_position = INITIAL_DIAL_POSITION;
    int zero_position_count = 0;

    file = fopen(inputFilePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open %s", inputFilePath);
        exit(EXIT_FAILURE);
    }

    while((line_length = getline(&line, &buffer_capacity, file)) != -1) {
        if (line[0] == 'L') {
            dial_position -= strtol(line + sizeof(char), NULL, 10);
        } else if (line[0] == 'R') {
            dial_position += strtol(line + sizeof(char), NULL, 10);
        } else {
            fprintf(stderr, "Invalid direction on line %d: expected L or R, got %c | full line: %s\n", line_number, line[0], line);
            exit(EXIT_FAILURE);
        }

        if (dial_position < 0) dial_position += NUM_DIAL_POSITIONS;
        dial_position %= NUM_DIAL_POSITIONS;

        if (dial_position == 0) zero_position_count++;

        line_number++;
    }

    fclose(file);
    if (line) free(line);

    return zero_position_count;
}
