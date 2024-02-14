#include "tests.h"

Test(_ffs, basic_test) {
    int value = 0b1000000;
    int expected_result = 7;
    
    // Test your _ffs implementation
    int result = _ffs(value);
    cr_assert_eq(result, expected_result, "Your _ffs implementation failed for value: %d: %d", value, result);
    
    // Test libc ffs implementation
    result = ffs(value);
    cr_assert_eq(result, expected_result, "Libc ffs failed for value: %d", value);
}
