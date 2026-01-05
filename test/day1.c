#include "day1.h"
#include "../src/day1.h"
#include "CUnit.h"
// NOLINTNEXTLINE(misc-include-cleaner) we're not using this directly, but not including it causes compiler errors related to CUnit types not being defined
#include <CUnit/CUError.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void it_gets_correct_answer_for_part_1_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day1Part1("data/day1/example.txt"), 3, "%d");
}

static void it_gets_correct_answer_for_part_2_with_example_data(void) {
  AOC_CU_ASSERT_EQUAL(day1Part2("data/day1/example.txt"), 6, "%d");
}

static void it_can_turn_right_a_small_amount(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_a_small_amount.txt"), 0,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_a_small_amount.txt"), 0,
      "%d");
}

static void it_can_turn_left_a_small_amount(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_a_small_amount.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_a_small_amount.txt"), 0, "%d");
}

static void it_can_turn_right_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_and_land_on_zero.txt"), 1,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_and_land_on_zero.txt"), 1,
      "%d");
}

static void it_can_turn_left_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_and_land_on_zero.txt"), 1,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_and_land_on_zero.txt"), 1,
      "%d");
}

static void it_can_turn_right_and_pass_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_and_pass_zero.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_and_pass_zero.txt"), 1, "%d");
}

static void it_can_turn_left_and_pass_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_and_pass_zero.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_and_pass_zero.txt"), 1, "%d");
}

static void it_can_turn_right_from_zero_a_small_amount(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_from_zero_a_small_amount.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_from_zero_a_small_amount.txt"),
      1, "%d");
}

static void it_can_turn_left_from_zero_a_small_amount(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_from_zero_a_small_amount.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_from_zero_a_small_amount.txt"),
      1, "%d");
}

static void it_can_turn_right_from_zero_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_from_zero_and_land_on_zero.txt"),
      2, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_from_zero_and_land_on_zero.txt"),
      2, "%d");
}

static void it_can_turn_left_from_zero_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_from_zero_and_land_on_zero.txt"),
      2, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_from_zero_and_land_on_zero.txt"),
      2, "%d");
}

static void it_can_turn_right_from_zero_and_pass_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_from_zero_and_pass_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_from_zero_and_pass_zero.txt"),
      2, "%d");
}

static void it_can_turn_left_from_zero_and_pass_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_from_zero_and_pass_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_from_zero_and_pass_zero.txt"),
      2, "%d");
}

static void it_can_turn_right_by_over_100_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_by_over_100_and_land_on_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_by_over_100_and_land_on_zero.txt"),
      3, "%d");
}

static void it_can_turn_left_by_over_100_and_land_on_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_by_over_100_and_land_on_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_by_over_100_and_land_on_zero.txt"),
      3, "%d");
}

static void it_can_turn_right_by_over_100_and_miss_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_by_over_100_and_miss_zero.txt"),
      0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_by_over_100_and_miss_zero.txt"),
      2, "%d");
}

static void it_can_turn_left_by_over_100_and_miss_zero(void) {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_by_over_100_and_miss_zero.txt"),
      0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_by_over_100_and_miss_zero.txt"),
      2, "%d");
}

int day1CreateTestSuite(void) {
  struct AOC_CU_TEST_DEFINITION test_definitions[] = {
    AOC_CU_INIT_TEST_DEFINITION(it_gets_correct_answer_for_part_1_with_example_data),
    AOC_CU_INIT_TEST_DEFINITION(it_gets_correct_answer_for_part_2_with_example_data),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_a_small_amount),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_a_small_amount),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_and_pass_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_and_pass_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_from_zero_a_small_amount),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_from_zero_a_small_amount),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_from_zero_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_from_zero_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_from_zero_and_pass_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_from_zero_and_pass_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_by_over_100_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_by_over_100_and_land_on_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_right_by_over_100_and_miss_zero),
    AOC_CU_INIT_TEST_DEFINITION(it_can_turn_left_by_over_100_and_miss_zero),
  };

  return AOC_CU_addSuite(test_definitions, sizeof(test_definitions) / sizeof(test_definitions[0]));
}
