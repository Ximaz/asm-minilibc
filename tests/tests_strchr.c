#include "tests.h"

Test(_strchr, character_found) {
    const char *str = "hello world";
    int character = 'o';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Character not found when it should have been.");
}

Test(_strchr, character_not_found) {
    const char *str = "hello world";
    int character = 'z';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Character found when it shouldn't have been.");
}

Test(_strchr, null_character) {
    const char *str = "hello world";
    int character = '\0';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Null character test failed.");
}

Test(_strchr, character_at_end) {
    const char *str = "hello world";
    int character = '\0';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Character at the end test failed.");
}

Test(_strchr, character_at_beginning) {
    const char *str = "hello world";
    int character = 'h';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Character at the beginning test failed.");
}

Test(_strchr, character_repeated) {
    const char *str = "hello world";
    int character = 'l';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Repeated character test failed.");
}

Test(_strchr, character_not_present) {
    const char *str = "hello world";
    int character = 'z';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Character not present test failed.");
}

Test(_strchr, empty_string) {
    const char *str = "";
    int character = 'a';
    char *result_custom = _strchr(str, character);
    char *result_libc = strchr(str, character);
    cr_assert_eq(result_custom, result_libc, "Empty string test failed.");
}

Test(_strchr, null) {
    const char *str = NULL;
    int character = 'a';
    CMP_CRASH_2(strrchr, _strchr, str, character);
}
