#include "tests.h"

Test(_strncmp, equal_strings) {
    const char *s1 = "hello";
    const char *s2 = "hello";
    size_t n = 5;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for equal strings.");
}

Test(_strncmp, s1_greater_than_s2) {
    const char *s1 = "world";
    const char *s2 = "hello";
    size_t n = 5;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for s1 greater than s2.");
}

Test(_strncmp, s1_less_than_s2) {
    const char *s1 = "apple";
    const char *s2 = "banana";
    size_t n = 5;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for s1 less than s2.");
}

Test(_strncmp, empty_string) {
    const char *s1 = "";
    const char *s2 = "";
    size_t n = 0;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for empty strings.");
}

Test(_strncmp, null_strings) {
    const char *s1 = NULL;
    const char *s2 = NULL;
    size_t n = 0;
    CMP_CRASH_3(strncmp, _strncmp, s1, s2, n);
}

Test(_strncmp, s1_null) {
    const char *s1 = NULL;
    const char *s2 = "hello";
    size_t n = 5;
    CMP_CRASH_3(strncmp, _strncmp, s1, s2, n);
}

Test(_strncmp, s2_null) {
    const char *s1 = "hello";
    const char *s2 = NULL;
    size_t n = 5;
    CMP_CRASH_3(strncmp, _strncmp, s1, s2, n);
}

Test(_strncmp, mixed_case) {
    const char *s1 = "HeLLo";
    const char *s2 = "hello";
    size_t n = 5;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for mixed case strings.");
}

Test(_strncmp, compare_part_of_string) {
    const char *s1 = "hello world";
    const char *s2 = "hello there";
    size_t n = 5;
    int result_custom = _strncmp(s1, s2, n);
    int result_libc = strncmp(s1, s2, n);
    cr_assert_eq(result_custom, result_libc, "Comparison failed for part of string.");
}
