#include "day1.h"
#include "../src/day1.h"
#include "CUnit.h"
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>

void it_gets_correct_answer_for_part_1_with_example_data() {
  AOC_CU_ASSERT_EQUAL(day1Part1("data/day1/example1.txt"), 3, "%d");
}

void it_gets_correct_answer_for_part_2_with_example_data() {
  AOC_CU_ASSERT_EQUAL(day1Part2("data/day1/example1.txt"), 6, "%d");
}

void it_can_turn_right_a_small_amount() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_a_small_amount.txt"), 0,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_a_small_amount.txt"), 0,
      "%d");
}

void it_can_turn_left_a_small_amount() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_a_small_amount.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_a_small_amount.txt"), 0, "%d");
}

void it_can_turn_right_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_and_land_on_zero.txt"), 1,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_and_land_on_zero.txt"), 1,
      "%d");
}

void it_can_turn_left_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_and_land_on_zero.txt"), 1,
      "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_and_land_on_zero.txt"), 1,
      "%d");
}

void it_can_turn_right_and_pass_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_and_pass_zero.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_and_pass_zero.txt"), 1, "%d");
}

void it_can_turn_left_and_pass_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_and_pass_zero.txt"), 0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_and_pass_zero.txt"), 1, "%d");
}

void it_can_turn_right_from_zero_a_small_amount() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_from_zero_a_small_amount.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_from_zero_a_small_amount.txt"),
      1, "%d");
}

void it_can_turn_left_from_zero_a_small_amount() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_from_zero_a_small_amount.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_from_zero_a_small_amount.txt"),
      1, "%d");
}

void it_can_turn_right_from_zero_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_from_zero_and_land_on_zero.txt"),
      2, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_from_zero_and_land_on_zero.txt"),
      2, "%d");
}

void it_can_turn_left_from_zero_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_from_zero_and_land_on_zero.txt"),
      2, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_from_zero_and_land_on_zero.txt"),
      2, "%d");
}

void it_can_turn_right_from_zero_and_pass_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_right_from_zero_and_pass_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_right_from_zero_and_pass_zero.txt"),
      2, "%d");
}

void it_can_turn_left_from_zero_and_pass_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1("test/data/day1/it_can_turn_left_from_zero_and_pass_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2("test/data/day1/it_can_turn_left_from_zero_and_pass_zero.txt"),
      2, "%d");
}

void it_can_turn_right_by_over_100_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_by_over_100_and_land_on_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_by_over_100_and_land_on_zero.txt"),
      3, "%d");
}

void it_can_turn_left_by_over_100_and_land_on_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_by_over_100_and_land_on_zero.txt"),
      1, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_by_over_100_and_land_on_zero.txt"),
      3, "%d");
}

void it_can_turn_right_by_over_100_and_miss_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_right_by_over_100_and_miss_zero.txt"),
      0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_right_by_over_100_and_miss_zero.txt"),
      2, "%d");
}

void it_can_turn_left_by_over_100_and_miss_zero() {
  AOC_CU_ASSERT_EQUAL(
      day1Part1(
          "test/data/day1/it_can_turn_left_by_over_100_and_miss_zero.txt"),
      0, "%d");
  AOC_CU_ASSERT_EQUAL(
      day1Part2(
          "test/data/day1/it_can_turn_left_by_over_100_and_miss_zero.txt"),
      2, "%d");
}

int day1CreateTestSuite() {
  CU_pSuite suite = NULL;

  suite = CU_add_suite("Day 1", NULL, NULL);
  if (suite == NULL)
    return EXIT_FAILURE;

  CU_ADD_TEST(suite, it_gets_correct_answer_for_part_1_with_example_data);
  CU_ADD_TEST(suite, it_gets_correct_answer_for_part_2_with_example_data);
  CU_ADD_TEST(suite, it_can_turn_right_a_small_amount);
  CU_ADD_TEST(suite, it_can_turn_left_a_small_amount);
  CU_ADD_TEST(suite, it_can_turn_right_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_left_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_right_and_pass_zero);
  CU_ADD_TEST(suite, it_can_turn_left_and_pass_zero);
  CU_ADD_TEST(suite, it_can_turn_right_from_zero_a_small_amount);
  CU_ADD_TEST(suite, it_can_turn_left_from_zero_a_small_amount);
  CU_ADD_TEST(suite, it_can_turn_right_from_zero_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_left_from_zero_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_right_from_zero_and_pass_zero);
  CU_ADD_TEST(suite, it_can_turn_left_from_zero_and_pass_zero);
  CU_ADD_TEST(suite, it_can_turn_right_by_over_100_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_left_by_over_100_and_land_on_zero);
  CU_ADD_TEST(suite, it_can_turn_right_by_over_100_and_miss_zero);
  CU_ADD_TEST(suite, it_can_turn_left_by_over_100_and_miss_zero);

  return EXIT_SUCCESS;
}
