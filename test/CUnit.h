#ifndef AOC25_TEST_CUNIT_H
#define AOC25_TEST_CUNIT_H

#define AOC_CU_ASSERT_EQUAL(actual, expected, format)                          \
  {                                                                            \
    typeof(actual) actual_value = actual;                                      \
    typeof(expected) expected_value = expected;                                \
    char strCondition[255] = {0};                                              \
    snprintf(strCondition, sizeof(strCondition),                               \
             "AOC_CU_ASSERT_EQUAL(" format ", " format ")", actual_value,      \
             expected_value);                                                  \
    CU_assertImplementation(actual_value == expected_value, __LINE__,          \
                            strCondition, __FILE__, "", CU_FALSE);             \
  }

#endif
