#include "day1.h"
#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int failedCount;

  if (CU_initialize_registry() != CUE_SUCCESS) {
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to initialise CUnit registry: %s",
            CU_get_error_msg());
    return CU_get_error();
  }

  if (day1CreateTestSuite() != EXIT_SUCCESS) {
    CU_cleanup_registry();
    // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
    fprintf(stderr, "Failed to create day 1 test suite: %s",
            CU_get_error_msg());
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  failedCount = CU_get_number_of_failures();

  CU_cleanup_registry();

  return failedCount != 0;
}
