#include "day4.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// NOLINTNEXTLINE(misc-include-cleaner)
#include <sys/types.h>

enum { MAX_GRID_DIM = 200, PAPER_ROLL_SYMBOL = '@', MAX_NEIGHBOUR_COUNT = 4 };

struct Grid {
  unsigned int width;
  unsigned int height;
  bool contents[MAX_GRID_DIM][MAX_GRID_DIM];
};

static void parseFile(char *inputFilePath, struct Grid *worldGrid) {
  FILE *file = NULL;
  char *line = NULL;
  size_t line_capacity = 0;
  // NOLINTNEXTLINE(misc-include-cleaner)
  ssize_t line_length = 0;
  unsigned int line_number = 0;

  file = fopen(inputFilePath, "r");
  exit_if(file == NULL, "Failed to open %s\n", inputFilePath);

  while ((line_length = getline(&line, &line_capacity, file)) != -1) {
    line = trim(line);

    if (line_number == 0) {
      worldGrid->width = (unsigned int)strlen(line);
    } else {
      exit_if(worldGrid->width != (unsigned int)strlen(line), "Grid does not have consistent width. First line width: %u, line %u width: %lu", worldGrid->width, line_number, strlen(line));
    }

    for (int i = 0; i < line_length; i++) {
      worldGrid->contents[line_number][i] = line[i] == PAPER_ROLL_SYMBOL;
    }

    line_number++;
  }

  worldGrid->height = line_number;

  exit_if(fclose(file) != 0, "Failed to close file handle\n");

  if (line != NULL) {
    free(line);
  }
}

static int countNeighbours(struct Grid *worldGrid, int centreX, int centreY) {
  int neighbour_count = 0;

  for (int yOffset = -1; yOffset <= 1; yOffset++) {
    for (int xOffset = -1; xOffset <= 1; xOffset++) {
      if ((xOffset == 0 && yOffset == 0) || (centreX + xOffset < 0 || (int)worldGrid->width <= centreX + xOffset) || (centreY + yOffset < 0 || (int)worldGrid->height <= centreY + yOffset)) {
        continue;
      }

      if (worldGrid->contents[centreY + yOffset][centreX + xOffset]) {
        neighbour_count++;
      }
    }
  }

  return neighbour_count;
}

long day4Part1(char *inputFilePath) {
  struct Grid world_grid = {
    .width = 0,
    .height = 0,
  };
  long result = 0;

  parseFile(inputFilePath, &world_grid);

  for (int y = 0; y < (int)world_grid.height; y++) {
    for (int x = 0; x < (int)world_grid.width; x++) {
      if (!world_grid.contents[y][x]) {
        continue;
      }

      if (countNeighbours(&world_grid, x, y) < MAX_NEIGHBOUR_COUNT) {
        result++;
      }
    }
  }

  return result;
}
