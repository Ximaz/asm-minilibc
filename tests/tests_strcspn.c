#include "tests.h"


Test(_strcspn, compare_with_libc) {
    const char* str1 = "hello world";
    const char* reject1 = "aeiou";

    size_t result_custom = _strcspn(str1, reject1);
    size_t result_libc = strcspn(str1, reject1);

    printf("%ld %ld\n", result_custom, result_libc);

    cr_assert_eq(result_custom, result_libc, "Custom strcspn result does not match libc strcspn.");

    const char* str2 = "12345";
    const char* reject2 = "aeiou";

    result_custom = _strcspn(str2, reject2);
    result_libc = strcspn(str2, reject2);

    cr_assert_eq(result_custom, result_libc, "Custom strcspn result does not match libc strcspn.");

    const char* str3 = "hello world";
    const char* reject3 = "";

    result_custom = _strcspn(str3, reject3);
    result_libc = strcspn(str3, reject3);

    cr_assert_eq(result_custom, result_libc, "Custom strcspn result does not match libc strcspn.");

    const char* str4 = "";
    const char* reject4 = "aeiou";

    result_custom = _strcspn(str4, reject4);
    result_libc = strcspn(str4, reject4);

    cr_assert_eq(result_custom, result_libc, "Custom strcspn result does not match libc strcspn.");
}

Test(_strcspn, null_ptr) {
    CMP_CRASH_2(strcspn, _strcspn, NULL, "valid");
    CMP_CRASH_2(strcspn, _strcspn, "valid", NULL);
    CMP_CRASH_2(strcspn, _strcspn, NULL, NULL);
}
