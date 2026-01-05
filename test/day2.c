#include "day2.h"
#include "../src/day2.h"
#include "CUnit.h"
// NOLINTNEXTLINE(misc-include-cleaner) we're not using this directly, but not including it causes compiler errors related to CUnit types not being defined
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <_string.h>
#include <stdlib.h>

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day2Part1("data/day2/example.txt"), 1227775554L, "%ld");
}

static void it_gets_correct_answer_for_part_2_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day2Part2("data/day2/example.txt"), 4174379265L, "%ld");
}

int day2CreateTestSuite(void) {
  CU_pSuite suite = NULL;

  suite = CU_add_suite("Day 2", NULL, NULL);
  if (suite == NULL) {
    return EXIT_FAILURE;
  }

  CU_ADD_TEST(suite, it_gets_correct_answer_for_part_1_with_example_data);
  CU_ADD_TEST(suite, it_gets_correct_answer_for_part_2_with_example_data);

  return EXIT_SUCCESS;
}
