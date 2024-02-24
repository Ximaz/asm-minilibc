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

Test(strstr_comparison, basic_test) {
    const char *haystack = "hello world";
    const char *needle = "world";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match for basic test");
}

Test(strstr_comparison, needle_not_found) {
    const char *haystack = "hello world";
    const char *needle = "foo";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match when needle is not found");
}

Test(strstr_comparison, empty_needle) {
    const char *haystack = "hello world";
    const char *needle = "";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match for empty needle");
}

Test(strstr_comparison, empty_haystack) {
    const char *haystack = "";
    const char *needle = "world";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match for empty haystack");
}

Test(strstr_comparison, both_empty) {
    const char *haystack = "";
    const char *needle = "";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match for both empty strings");
}

Test(strstr_comparison, needle_longer_than_haystack) {
    const char *haystack = "hello";
    const char *needle = "hello world";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match when needle is longer than haystack");
}

Test(strstr_comparison, needle_at_end_of_haystack) {
    const char *haystack = "hello world";
    const char *needle = "world";
    haystack += 6; // Move haystack pointer to just before "world"
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match when needle is at the end of haystack");
}

// Test case where needle appears multiple times in haystack
Test(strstr_comparison, multiple_occurrences_of_needle) {
    const char *haystack = "hello hello hello";
    const char *needle = "hello";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match for multiple occurrences of needle");
}
Test(strstr_comparison, needle_longer_than_haystack_two) {
    const char *haystack = "hello";
    const char *needle = "hello world";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match when needle is longer than haystack");
    cr_assert_null(_strstr_result, "Custom strstr should return NULL when needle is longer than haystack");
}
Test(strstr_comparison, needle_at_end_of_haystack_two) {
    const char *haystack = "hello world";
    const char *needle = "world";
    char *libc_result = strstr(haystack, needle);
    char *_strstr_result = _strstr(haystack, needle);
    cr_assert_eq(libc_result, _strstr_result, "Results do not match when needle is at the end of haystack");
}
