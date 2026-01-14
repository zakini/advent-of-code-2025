#ifndef AOC25_TEST_CUNIT_H
#define AOC25_TEST_CUNIT_H

#include <CUnit/CUnit.h>
#include <stddef.h>
#include <stdio.h>

#define AOC_CU_ASSERT_EQUAL(actual, expected, format)                          \
  do {                                                                         \
    __typeof__(actual) actual_value = actual;                                  \
    __typeof__(expected) expected_value = expected;                            \
    char strCondition[255] = {0};                                              \
    snprintf(strCondition, sizeof(strCondition),                               \
             "AOC_CU_ASSERT_EQUAL(" format ", " format ")", actual_value,      \
             expected_value);                                                  \
    CU_assertImplementation(actual_value == expected_value, __LINE__,          \
                            strCondition, __FILE__, "", CU_FALSE);             \
  } while (0)

typedef void (*AOC_CU_testFunction)(void);

struct AOC_CU_TEST_DEFINITION {
  char *name;
  AOC_CU_testFunction func;
};
#define AOC_CU_INIT_TEST_DEFINITION(a) {#a, a}

int AOC_CU_addSuite(struct AOC_CU_TEST_DEFINITION testDefs[],
                    size_t testDefsSize);

#endif
