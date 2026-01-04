#include "day1.h"
#include "day2.h"
#include <stdio.h>

int main(void) {
  printf("Day 1\n=====\nPart 1: %d\nPart 2: %d\n",
         day1Part1("data/day1/data.txt"), day1Part2("data/day1/data.txt"));
  printf("\nDay 2\n=====\nPart 1: %ld\n", day2Part1("data/day2/data.txt"));

  return 0;
}
