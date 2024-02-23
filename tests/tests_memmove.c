#include "tests.h"

Test(_memmove, compare_with_libc) {
    char buffer_custom[10];
    char buffer_libc[10];

    strcpy(buffer_custom, "abcdefghi");
    strcpy(buffer_libc, "abcdefghi");

    _memmove(buffer_custom + 3, buffer_custom, 3);
    memmove(buffer_libc + 3, buffer_libc, 3);

    int cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memmove result does not match libc memmove.");

    strcpy(buffer_custom, "abcdefghi");
    strcpy(buffer_libc, "abcdefghi");

    _memmove(buffer_custom, buffer_custom + 3, 3);
    memmove(buffer_libc, buffer_libc + 3, 3);
    cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memmove result does not match libc memmove.");

    strcpy(buffer_custom, "abcdefghi");
    strcpy(buffer_libc, "abcdefghi");

    _memmove(buffer_custom, buffer_custom + 3, 5);
    memmove(buffer_libc, buffer_libc + 3, 5);

    cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memmove result does not match libc memmove.");
}

Test(_memmove, null_pointers) {
    CMP_CRASH_3(memmove, _memmove, NULL, NULL, 3);
}

Test(memmove, overlapping) {
    char buffer_custom[] = "123456789";
    char buffer_libc[] = "123456789";

    _memmove(buffer_custom + 3, buffer_custom, 6);
    memmove(buffer_libc + 3, buffer_libc, 6);
    cr_assert_str_eq(buffer_custom, buffer_libc, "Custom memmove does not match libc memmove");
}
