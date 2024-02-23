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

Test(strpbrk, comparison_with_libc) {
    // Test case 1: Comparing custom implementation with libc's strpbrk
    const char *str_custom = "abcdef";
    const char *str_libc = "abcdef";
    const char *needle = "bcde";

    char *result_custom = _strpbrk(str_custom, needle);
    char *result_libc = strpbrk(str_libc, needle);

    cr_assert_eq(result_custom, result_libc, "Custom strpbrk does not match libc strpbrk");

    // Test case 2: Comparing custom implementation with libc's strpbrk with empty needle
    const char *str_custom_empty = "abcdef";
    const char *str_libc_empty = "abcdef";
    const char *empty_needle = "";

    char *result_custom_empty = _strpbrk(str_custom_empty, empty_needle);
    char *result_libc_empty = strpbrk(str_libc_empty, empty_needle);

    cr_assert_eq(result_custom_empty, result_libc_empty, "Custom strpbrk with empty needle does not match libc strpbrk");
}

Test(strpbrk, comparison_with_libc_edge_cases) {
    // Test case 1: Comparing custom implementation with libc's strpbrk
    const char *str_custom = "abcdef";
    const char *str_libc = "abcdef";
    const char *needle = "bcde";

    char *result_custom = _strpbrk(str_custom, needle);
    char *result_libc = strpbrk(str_libc, needle);

    cr_assert_eq(result_custom, result_libc, "Custom strpbrk does not match libc strpbrk");

    // Test case 2: Comparing custom implementation with libc's strpbrk with empty needle
    const char *str_custom_empty = "abcdef";
    const char *str_libc_empty = "abcdef";
    const char *empty_needle = "";

    char *result_custom_empty = _strpbrk(str_custom_empty, empty_needle);
    char *result_libc_empty = strpbrk(str_libc_empty, empty_needle);

    cr_assert_eq(result_custom_empty, result_libc_empty, "Custom strpbrk with empty needle does not match libc strpbrk");

    // Test case 3: Empty string as input
    const char *str_empty = "";
    const char *needle_nonempty = "abc";

    char *result_empty = _strpbrk(str_empty, needle_nonempty);
    cr_assert_null(result_empty, "Failed test case with empty string as input");

    // Test case 4: Empty needle
    const char *str_nonempty = "abcdef";
    const char *needle_empty = "";

    char *result_needle_empty = _strpbrk(str_nonempty, needle_empty);
    cr_assert_null(result_needle_empty, "Failed test case with empty needle");

    // Test case 5: None of the characters in the needle are found in the string
    const char *str_no_match = "abcdef";
    const char *needle_no_match = "xyz";

    char *result_no_match = _strpbrk(str_no_match, needle_no_match);
    cr_assert_null(result_no_match, "Failed test case with no matching characters");

    // Test case 6: String contains only characters in the needle
    const char *str_all_match = "abc";
    const char *needle_all_match = "abc";

    char *result_all_match = _strpbrk(str_all_match, needle_all_match);
    cr_assert_str_eq(result_all_match, "abc", "Failed test case with all characters matching");
}

Test(strpbrk, comparison_with_libc_two) {
    // Test case 1: Comparing custom implementation with libc's strpbrk
    const char *str_custom = "abcdef";
    const char *str_libc = "abcdef";
    const char *needle = "bcde";

    char *result_custom = _strpbrk(str_custom, needle);
    char *result_libc = strpbrk(str_libc, needle);

    cr_assert_eq(result_custom, result_libc, "Custom strpbrk does not match libc strpbrk");

    // Test case 2: Comparing custom implementation with libc's strpbrk with empty needle
    const char *str_custom_empty = "abcdef";
    const char *str_libc_empty = "abcdef";
    const char *empty_needle = "";

    char *result_custom_empty = _strpbrk(str_custom_empty, empty_needle);
    char *result_libc_empty = strpbrk(str_libc_empty, empty_needle);

    cr_assert_eq(result_custom_empty, result_libc_empty, "Custom strpbrk with empty needle does not match libc strpbrk");

    // Test case 3: Empty string as input
    const char *str_empty = "";
    const char *needle_nonempty = "abc";

    char *result_empty = _strpbrk(str_empty, needle_nonempty);
    cr_assert_null(result_empty, "Failed test case with empty string as input");

    // Test case 4: Empty needle
    const char *str_nonempty = "abcdef";
    const char *needle_empty = "";

    char *result_needle_empty = _strpbrk(str_nonempty, needle_empty);
    cr_assert_null(result_needle_empty, "Failed test case with empty needle");

    // Test case 5: None of the characters in the needle are found in the string
    const char *str_no_match = "abcdef";
    const char *needle_no_match = "xyz";

    char *result_no_match = _strpbrk(str_no_match, needle_no_match);
    cr_assert_null(result_no_match, "Failed test case with no matching characters");

    // Test case 6: String contains only characters in the needle
    const char *str_all_match = "abc";
    const char *needle_all_match = "abc";

    char *result_all_match = _strpbrk(str_all_match, needle_all_match);
    cr_assert_str_eq(result_all_match, "abc", "Failed test case with all characters matching");

    // Test case 7: Needle has more characters than haystack
    const char *str_short = "abc";
    const char *needle_long = "abcd";

    cr_assert_str_eq(strpbrk(str_short, needle_long), _strpbrk(str_short, needle_long));

    // Test case 8: Needle and haystack both empty
    const char *str_empty_both = "";
    const char *needle_empty_both = "";

    cr_assert_eq(strpbrk(str_empty_both, needle_empty_both), _strpbrk(str_empty_both, needle_empty_both));
}
