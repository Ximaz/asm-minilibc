#include "tests.h"

Test(_memcpy, compare_with_libc) {
    char buffer_custom[10];
    char buffer_libc[10];

    strcpy(buffer_custom, "abcdefghi");
    strcpy(buffer_libc, "abcdefghi");

    _memcpy(buffer_custom + 3, buffer_custom, 3);
    memcpy(buffer_libc + 3, buffer_libc, 3);

    int cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memcpy result does not match libc memcpy.");

    strcpy(buffer_custom, "abcdefghi");
    strcpy(buffer_libc, "abcdefghi");

    _memcpy(buffer_custom, buffer_custom + 3, 5);
    memcpy(buffer_libc, buffer_libc + 3, 5);

    cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memcpy result does not match libc memcpy.");
}

Test(_memcpy, null_pointer) {
    CMP_CRASH_3(memcpy, _memcpy, NULL, NULL, 3);
}
