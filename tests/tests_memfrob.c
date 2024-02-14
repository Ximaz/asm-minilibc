#include "tests.h"

Test(_memfrob, basic_test)
{
    const char original[] = "Hello, world!";
    const size_t len = strlen(original);
    char *copy = malloc(len + 1);
    strncpy(copy, original, len + 1);
    
    _memfrob(copy, len);
    cr_assert_str_neq(copy, original, "Original data was modified");
    _memfrob(copy, len);
    cr_assert_str_eq(copy, original, "Data was not restored after applying memfrob twice");
    free(copy);
}
