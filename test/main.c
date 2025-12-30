#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/CUError.h>
#include <CUnit/Basic.h>
#include "day1.h"

int main() {
    int failedCount;

    if (CU_initialize_registry() != CUE_SUCCESS) {
        fprintf(stderr, "Failed to initialise CUnit registry: %s", CU_get_error_msg());
        return CU_get_error();
    }

    if (day1CreateTestSuite() != EXIT_SUCCESS) {
        CU_cleanup_registry();
        fprintf(stderr, "Failed to create day 1 test suite: %s", CU_get_error_msg());
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    failedCount = CU_get_number_of_failures();

    CU_cleanup_registry();

    return failedCount != 0;
}
