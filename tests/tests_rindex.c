#include "tests.h"

Test(_rindex, compare_with_libc) {
    const char* str = "hello world";

    char* result_custom = _rindex(str, 'o');
    char* result_libc = rindex(str, 'o');

    cr_assert_eq(result_custom, result_libc, "Custom rindex result does not match libc rindex.");

    result_custom = _rindex(str, 'd');
    result_libc = rindex(str, 'd');

    cr_assert_eq(result_custom, result_libc, "Custom rindex result does not match libc rindex.");

    result_custom = _rindex(str, 'z');
    result_libc = rindex(str, 'z');

    cr_assert_eq(result_custom, result_libc, "Custom rindex result does not match libc rindex.");

    result_custom = _rindex(str, '\0');
    result_libc = rindex(str, '\0');

    cr_assert_eq(result_custom, result_libc, "Custom rindex result does not match libc rindex.");
}

Test(_rindex, empty_string) {
    const char* str = "";

    char* result_custom = _rindex(str, 'a');
    char* result_libc = rindex(str, 'a');

    cr_assert_eq(result_custom, result_libc, "Custom rindex result does not match libc rindex.");
}