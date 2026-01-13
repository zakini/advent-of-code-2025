#include "day3.h"
#include "../src/day3.h"
#include "CUnit.h"
// NOLINTNEXTLINE(misc-include-cleaner) we're not using this directly, but not including it causes compiler errors related to CUnit types not being defined
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdlib.h>

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day3Part1("data/day3/example.txt"), 357, "%d");
}

int day3CreateTestSuite(void) {
  struct AOC_CU_TEST_DEFINITION test_definitions[] = {
    AOC_CU_INIT_TEST_DEFINITION(it_gets_correct_answer_for_part_1_with_example_data),
  };

  return AOC_CU_addSuite(test_definitions, sizeof(test_definitions) / sizeof(test_definitions[0]));
}
