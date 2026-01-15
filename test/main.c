#include "day1.h"
#include "day2.h"
#include "day3.h"
#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int (*suite_definitions[])(void) = {
      day1CreateTestSuite,
      day2CreateTestSuite,
      day3CreateTestSuite,
  };
  unsigned int failedCount;

  if (CU_initialize_registry() != CUE_SUCCESS) {
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to initialise CUnit registry: %s\n",
            CU_get_error_msg());
    return EXIT_FAILURE;
  }

  for (size_t i = 0;
       i < (sizeof(suite_definitions) / sizeof(suite_definitions[0])); i++) {
    if (suite_definitions[i]() != EXIT_SUCCESS) {
      CU_cleanup_registry();
      // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
      fprintf(stderr, "Failed to create test suite %lu: %s\n", i,
              CU_get_error_msg());
      return EXIT_FAILURE;
    }
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  failedCount = CU_get_number_of_failures();

  CU_cleanup_registry();

  return failedCount != 0;
}
