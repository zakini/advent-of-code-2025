#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "day1.h"
#include "../src/day1.h"

void exampleTest();

int day1CreateTestSuite() {
    CU_pSuite suite = NULL;

    suite = CU_add_suite("Day 1", NULL, NULL);
    if (suite == NULL) return EXIT_FAILURE;

    CU_add_test(suite, "exampleTest", exampleTest);

    return EXIT_SUCCESS;
}

void exampleTest() {
    CU_ASSERT_EQUAL(3, day1("data/day1/example1.txt"))
}
