#include "day1.h"
#include "day2.h"
#include <stdio.h>

struct DayPart {
  long (*func)(char*);
  char *input_file_path;
};

struct Day {
  int day_number;
  struct DayPart parts[2];
};

int main(void) {
  struct Day days[] = {
    {1, {
      {day1Part1, "data/day1/data.txt"},
      {day1Part2, "data/day1/data.txt"},
    }},
    {2, {
      {day2Part1, "data/day2/data.txt"},
      {day2Part2, "data/day2/data.txt"},
    }},
  };

  for (size_t i = 0; i < sizeof(days) / sizeof(days[0]); i++) {
    printf("Day %d\n=====\n", days[i].day_number);
    printf("Part 1: %ld\n", days[i].parts[0].func(days[i].parts[0].input_file_path));
    printf("Part 2: %ld\n", days[i].parts[1].func(days[i].parts[1].input_file_path));
  }

  return 0;
}
