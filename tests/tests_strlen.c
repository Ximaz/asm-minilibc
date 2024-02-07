#include "tests.h"

Test(_strlen, test_one)
{
    char const *string = "";

    cr_assert(strlen(string) == _strlen(string));
}

Test(_strlen, test_two)
{
    char const *string = "ABCDEF\1\2\0ABCIDE";

    cr_assert(strlen(string) == _strlen(string));
}

Test(_strlen, test_three)
{
    CMP_CRASH_1(strlen, _strlen, NULL);
}
