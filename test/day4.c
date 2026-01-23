#include "day4.h"
#include "../src/day4.h"
#include "CUnit.h"

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day4Part1("data/day4/example.txt"), 13L, "%ld");
}

static void it_gets_correct_answer_for_part_2_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day4Part2("data/day4/example.txt"), 43L, "%ld");
}

int day4CreateTestSuite(void) {
  struct AOC_CU_TEST_DEFINITION test_definitions[] = {
      AOC_CU_INIT_TEST_DEFINITION(
          it_gets_correct_answer_for_part_1_with_example_data),
      AOC_CU_INIT_TEST_DEFINITION(
          it_gets_correct_answer_for_part_2_with_example_data),
  };

  return AOC_CU_addSuite("Day 4", test_definitions,
                         sizeof(test_definitions) /
                             sizeof(test_definitions[0]));
}
