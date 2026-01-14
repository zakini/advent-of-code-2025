#include "CUnit.h"
#include <CUnit/CUError.h>
// NOLINTNEXTLINE(misc-include-cleaner) we're not using this directly, but not including it causes compiler errors related to CUnit types not being defined
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int AOC_CU_addSuite(struct AOC_CU_TEST_DEFINITION testDefs[], size_t testDefsSize) {
  CU_pSuite suite = NULL;

  suite = CU_add_suite("Day 1", NULL, NULL);
  if (suite == NULL) {
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < testDefsSize; i++) {
    if (CU_add_test(suite, testDefs[i].name, testDefs[i].func) == NULL) {
      // NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently
      fprintf(stderr, "Failed to add test to suite: %s\n", CU_get_error_msg());
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
