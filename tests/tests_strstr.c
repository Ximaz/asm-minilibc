#include "tests.h"

Test(_strstr, needle_found) {
    const char *haystack = "hello world";
    const char *needle = "world";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Needle not found when it should have been.");
}

Test(_strstr, needle_not_found) {
    const char *haystack = "hello world";
    const char *needle = "foo";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Needle found when it shouldn't have been.");
}

Test(_strstr, needle_empty) {
    const char *haystack = "hello world";
    const char *needle = "";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Empty needle test failed.");
}

Test(_strstr, haystack_empty) {
    const char *haystack = "";
    const char *needle = "world";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Empty haystack test failed.");
}

Test(_strstr, both_empty) {
    const char *haystack = "";
    const char *needle = "";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Both empty strings test failed.");
}

Test(_strstr, needle_longer_than_haystack) {
    const char *haystack = "hello";
    const char *needle = "hello world";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Needle longer than haystack test failed.");
}

Test(_strstr, needle_at_beginning) {
    const char *haystack = "hello world";
    const char *needle = "hello";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Needle at beginning test failed.");
}

Test(_strstr, needle_at_end) {
    const char *haystack = "hello world";
    const char *needle = "world";
    char *result_custom = _strstr(haystack, needle);
    char *result_libc = strstr(haystack, needle);
    cr_assert_eq(result_custom, result_libc, "Needle at end test failed.");
}