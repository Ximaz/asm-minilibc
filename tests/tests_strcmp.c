#include "tests.h"

Test(_strcmp, equal_strings) {
    const char *s1 = "hello";
    const char *s2 = "hello";
    int result_custom = _strcmp(s1, s2);
    int result_libc = strcmp(s1, s2);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for equal strings.");
}

Test(_strcmp, s1_greater_than_s2) {
    const char *s1 = "world";
    const char *s2 = "hello";
    int result_custom = _strcmp(s1, s2);
    int result_libc = strcmp(s1, s2);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for s1 greater than s2.");
}

Test(_strcmp, s1_less_than_s2) {
    const char *s1 = "apple";
    const char *s2 = "banana";
    int result_custom = _strcmp(s1, s2);
    int result_libc = strcmp(s1, s2);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for s1 less than s2.");
}

Test(_strcmp, empty_string) {
    const char *s1 = "";
    const char *s2 = "";
    int result_custom = _strcmp(s1, s2);
    int result_libc = strcmp(s1, s2);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for empty strings.");
}

Test(_strcmp, null_strings) {
    const char *s1 = NULL;
    const char *s2 = NULL;
    CMP_CRASH_2(strcmp, _strcmp, s1, s2);
}

Test(_strcmp, s1_null) {
    const char *s1 = NULL;
    const char *s2 = "hello";
    CMP_CRASH_2(strcmp, _strcmp, s1, s2);
}

Test(_strcmp, s2_null) {
    const char *s1 = "hello";
    const char *s2 = NULL;
    CMP_CRASH_2(strcmp, _strcmp, s1, s2);
}

Test(_strcmp, mixed_case) {
    const char *s1 = "HeLLo";
    const char *s2 = "hello";
    int result_custom = _strcmp(s1, s2);
    int result_libc = strcmp(s1, s2);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for mixed case strings.");
}
