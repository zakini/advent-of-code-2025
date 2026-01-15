#include "day3.h"
#include "../src/day3.h"
#include "CUnit.h"
#include <stdlib.h>

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day3Part1("data/day3/example.txt"), 357L, "%ld");
}
static void it_gets_correct_answer_for_part_2_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day3Part2("data/day3/example.txt"), 3121910778619L,
                      "%ld");
}

int day3CreateTestSuite(void) {
  struct AOC_CU_TEST_DEFINITION test_definitions[] = {
      AOC_CU_INIT_TEST_DEFINITION(
          it_gets_correct_answer_for_part_1_with_example_data),
      AOC_CU_INIT_TEST_DEFINITION(
          it_gets_correct_answer_for_part_2_with_example_data),
  };

  return AOC_CU_addSuite(test_definitions, sizeof(test_definitions) /
                                               sizeof(test_definitions[0]));
}
