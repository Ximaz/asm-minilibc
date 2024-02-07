#include "tests.h"

Test(_strpbrk, match_found) {
    const char *str1 = "abcdef";
    const char *str2 = "def";
    char *result_custom = _strpbrk(str1, str2);
    char *result_libc = strpbrk(str1, str2);
    cr_assert_eq(result_custom, result_libc, "Match not found when it should have been.");
}

Test(_strpbrk, match_not_found) {
    const char *str1 = "abcdef";
    const char *str2 = "xyz";
    char *result_custom = _strpbrk(str1, str2);
    char *result_libc = strpbrk(str1, str2);
    cr_assert_eq(result_custom, result_libc, "Match found when it shouldn't have been.");
}

Test(_strpbrk, empty_str1) {
    const char *str1 = "";
    const char *str2 = "abc";
    char *result_custom = _strpbrk(str1, str2);
    char *result_libc = strpbrk(str1, str2);
    cr_assert_eq(result_custom, result_libc, "Empty str1 test failed.");
}

Test(_strpbrk, empty_str2) {
    const char *str1 = "abcdef";
    const char *str2 = "";
    char *result_custom = _strpbrk(str1, str2);
    char *result_libc = strpbrk(str1, str2);
    cr_assert_eq(result_custom, result_libc, "Empty str2 test failed.");
}

Test(_strpbrk, both_empty) {
    const char *str1 = "";
    const char *str2 = "";
    char *result_custom = _strpbrk(str1, str2);
    char *result_libc = strpbrk(str1, str2);
    cr_assert_eq(result_custom, result_libc, "Both empty strings test failed.");
}

Test(_strpbrk, str1_null) {
    const char *str1 = NULL;
    const char *str2 = "abc";
    CMP_CRASH_2(strpbrk, _strpbrk, str1, str2);
}

Test(_strpbrk, str2_null) {
    const char *str1 = "abcdef";
    const char *str2 = NULL;
    CMP_CRASH_2(strpbrk, _strpbrk, str1, str2);
}

Test(_strpbrk, all_null) {
    const char *str1 = NULL;
    const char *str2 = NULL;
    CMP_CRASH_2(strpbrk, _strpbrk, str1, str2);
}
