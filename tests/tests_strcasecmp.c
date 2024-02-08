#include "tests.h"

Test(_strcasecmp, compare_with_libc) {
    const char* str1 = "Hello";
    const char* str2 = "hello";

    int result_custom = _strcasecmp(str1, str2);
    int result_libc = strcasecmp(str1, str2);

    cr_assert_eq(result_custom, result_libc, "Custom strcasecmp result does not match libc strcasecmp.");

    const char* str3 = "World";
    const char* str4 = "world";

    result_custom = _strcasecmp(str3, str4);
    result_libc = strcasecmp(str3, str4);

    cr_assert_eq(result_custom, result_libc, "Custom strcasecmp result does not match libc strcasecmp.");

    const char* str5 = "abc";
    const char* str6 = "def";

    result_custom = _strcasecmp(str5, str6);
    result_libc = strcasecmp(str5, str6);

    cr_assert_eq(result_custom, result_libc, "Custom strcasecmp result does not match libc strcasecmp.");
}

Test(_strcasecmp, null_dest) {
    CMP_CRASH_2(strcasecmp, _strcasecmp, NULL, "Hello, World");
}

Test(_strcasecmp, null_src) {
    CMP_CRASH_2(strcasecmp, _strcasecmp, "Hello, World", NULL);
}
