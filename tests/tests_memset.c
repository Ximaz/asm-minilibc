#include "tests.h"

Test(_memset, compare_with_libc) {
    char buffer_custom[10];
    char buffer_libc[10];

    _memset(buffer_custom, 'A', sizeof(buffer_custom));
    memset(buffer_libc, 'A', sizeof(buffer_libc));

    int cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memset result does not match libc memset.");

    _memset(buffer_custom, 'B', sizeof(buffer_custom));
    memset(buffer_libc, 'B', sizeof(buffer_libc));

    cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memset result does not match libc memset.");

    _memset(buffer_custom, 'C', sizeof(buffer_custom));
    memset(buffer_libc, 'C', sizeof(buffer_libc));

    cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memset result does not match libc memset.");
}

Test(_memset, size_zero) {
    char buffer_custom[10] = { 5 };
    char buffer_libc[10] = { 5 };

    _memset(buffer_custom, 'X', 0);
    memset(buffer_libc, 'X', 0);

    int cmp_result = memcmp(buffer_custom, buffer_libc, sizeof(buffer_custom));
    cr_assert_eq(cmp_result, 0, "Custom memset with size 0 result does not match libc memset with size 0.");
}

Test(_memset, crash)
{
    CMP_CRASH_3(memset, _memset, NULL, 'A', 0);
}
