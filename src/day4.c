#include "day4.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_GRID_DIM 200
#define PAPER_ROLL_SYMBOL '@'
#define MAX_NEIGHBOUR_COUNT 4

long day4Part1(char *inputFilePath) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length = 0;
  unsigned int line_number = 0;

  bool world_grid[MAX_GRID_DIM][MAX_GRID_DIM];
  unsigned int grid_width = 0;
  unsigned int grid_height = 0;
  int neighbour_count = 0;
  long result = 0;

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while ((line_length = getline(&line, &line_capacity, file)) != -1) {
    line = trim(line);

    if (line_number == 0) {
      grid_width = (unsigned int)strlen(line);
    } else {
      exit_if(grid_width != (unsigned int)strlen(line), "Grid does not have consistent width. First line width: %u, line %u width: %lu", grid_width, line_number, strlen(line));
    }

    for (int i = 0; i < line_length; i++) {
      world_grid[line_number][i] = line[i] == PAPER_ROLL_SYMBOL;
    }

    line_number++;
  }

  grid_height = line_number;

  for (int y = 0; y < (int)grid_height; y++) {
    for (int x = 0; x < (int)grid_width; x++) {
      if (!world_grid[y][x]) {
        continue;
      }

      neighbour_count = 0;
      for (int yOffset = -1; yOffset <= 1; yOffset++) {
        for (int xOffset = -1; xOffset <= 1; xOffset++) {
          if ((xOffset == 0 && yOffset == 0) || (x + xOffset < 0 || (int)grid_width <= x + xOffset) || (y + yOffset < 0 || (int)grid_height <= y + yOffset)) {
            continue;
          }

          if (world_grid[y + yOffset][x + xOffset]) {
            neighbour_count++;
          }
        }
      }

      if (neighbour_count < MAX_NEIGHBOUR_COUNT) {
        result++;
      }
    }
  }

  return result;
}
