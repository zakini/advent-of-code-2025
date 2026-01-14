#include "day2.h"
#include "../src/day2.h"
#include "CUnit.h"
#include <stdlib.h>

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day2Part1("data/day2/example.txt"), 1227775554L, "%ld");
}

static void it_gets_correct_answer_for_part_2_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day2Part2("data/day2/example.txt"), 4174379265L, "%ld");
}

int day2CreateTestSuite(void) {
  struct AOC_CU_TEST_DEFINITION test_definitions[] = {
    AOC_CU_INIT_TEST_DEFINITION(it_gets_correct_answer_for_part_1_with_example_data),
    AOC_CU_INIT_TEST_DEFINITION(it_gets_correct_answer_for_part_2_with_example_data),
  };

  return AOC_CU_addSuite(test_definitions, sizeof(test_definitions) / sizeof(test_definitions[0]));
}
