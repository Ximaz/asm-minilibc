/*
** EPITECH PROJECT, 2022
** ASM
** File description:
** tests.c
*/

#include "tests.h"
#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>

static int nb_tested = 0;
static char *func_name = 0;
static int has_function_failed = 0;
static FILE *reports = 0;

#define START_TEST_SUITE(func) func_name = func; reports = (reports ? reports : fopen("reports.txt", "w+")); has_function_failed = 0; nb_tested = 1
#define TRY(boolean) (try_increase((boolean), passed, totalTested))

static void try_increase(bool hasPassed, int *passed, int *totalTested)
{
    if (hasPassed)
        *passed += 1;
    else {
        if (!has_function_failed) {
            fprintf(reports, "%s:\n", func_name);
            has_function_failed = 1;
        }
        fprintf(reports, "Failed test n°%d.\n", nb_tested);
    }
    *totalTested += 1;
    nb_tested++;
}

void test_strlen(func_size_t_ptr strlen, int *passed, int *totalTested)
{
    START_TEST_SUITE("strlen");

    TRY(strlen("abc") == 3);
    TRY(strlen("a") == 1);
    TRY(strlen("") == 0);
    TRY(strlen("\1\2\3hsvrfsdbv678") == 15);
}

void test_strchr(func_char_ptr strchr, int *passed, int *totalTested)
{
    START_TEST_SUITE("strchr");

    TRY(strchr("abc", 'a') == (char *)"abc");
    TRY(strchr("abc", 'b') == "abc" + 1);
    TRY(strchr("abc", 'c') == "abc" + 2);
    TRY(strchr("abc", 'd') == NULL);
    TRY(strchr("abc", '\0') && (*(char *)strchr("abc", '\0')) == 0);
    TRY(strchr("abc", '\1') == NULL);
    TRY(strchr("", 'a') == NULL);
    TRY(strchr("", '\0') && (*(char *)strchr("", '\0')) == 0);
}

void test_memset(func_ptr memset, int *passed, int *totalTested)
{
    START_TEST_SUITE("memset");

    char buf[] = "abc";

    memset(buf, 'a', 0);
    TRY(buf[0] == 'a' && buf[1] == 'b' && buf[2] == 'c');

    memset(buf, 'z', 1);
    TRY(buf[0] == 'z' && buf[1] == 'b' && buf[2] == 'c');

    memset(buf, 'z', 2);
    TRY(buf[0] == 'z' && buf[1] == 'z' && buf[2] == 'c');

    memset(buf, '0', 3);
    TRY(buf[0] == '0' && buf[1] == '0' && buf[2] == '0');
}

void test_memcpy(func_ptr memcpy, int *passed, int *totalTested)
{
    START_TEST_SUITE("memcpy");

    char buf[5] = "abc";
    memcpy(buf, "def", 3);
    TRY(buf[0] == 'd' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    memcpy(buf, "zzz", 0);
    TRY(buf[0] == 'd' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    memcpy(buf, "zzzzzzz", 1);
    TRY(buf[0] == 'z' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    buf[3] = 'u';
    buf[4] = 'v';
    memcpy(buf, "\0\0\0\0z", 4);
    TRY(buf[0] == 0 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0 && buf[4] == 'v');
}

void test_memmove(func_ptr memmove, int *passed, int *totalTested)
{
    START_TEST_SUITE("memmove");

    // Test memcpy
    char buf[5] = "abc";
    memmove(buf, "def", 3);
    TRY(buf[0] == 'd' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    memmove(buf, "zzz", 0);
    TRY(buf[0] == 'd' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    memmove(buf, "zzzzzzz", 1);
    TRY(buf[0] == 'z' && buf[1] == 'e' && buf[2] == 'f' && buf[3] == 0);

    buf[3] = 'u';
    buf[4] = 'v';
    memmove(buf, "\0\0\0\0z", 4);
    TRY(buf[0] == 0 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0 && buf[4] == 'v');

    // Test overlap 1
    int *arr_src = malloc(sizeof(int) * 14);
    int *arr_dest = arr_src + 5;

    for (int i = 0; i < 9; i++)
        arr_src[i] = i;
    memmove(arr_dest, arr_src, sizeof(int) * 9);
    TRY(arr_dest[0] == 0 && arr_dest[1] == 1 && arr_dest[2] == 2 && arr_dest[3] == 3 && arr_dest[4] == 4 && arr_dest[5] == 5 && arr_dest[6] == 6 && arr_dest[7] == 7 && arr_dest[8] == 8);
    free(arr_src);

    // Test overlap, in the other way
    arr_dest = malloc(sizeof(int) * 14);
    arr_src = arr_dest + 5;
    for (int i = 0; i < 9; i++)
        arr_src[i] = i;
    memmove(arr_dest, arr_src, sizeof(int) * 9);
    TRY(arr_dest[0] == 0 && arr_dest[1] == 1 && arr_dest[2] == 2 && arr_dest[3] == 3 && arr_dest[4] == 4 && arr_dest[5] == 5 && arr_dest[6] == 6 && arr_dest[7] == 7 && arr_dest[8] == 8);
    free(arr_dest);
}

void test_strcmp(func_int_ptr strcmp, int *passed, int *totalTested)
{
    START_TEST_SUITE("strchr");

    TRY(strcmp("abc", "abc") == 0);
    TRY(strcmp("abc", "abd") < 0);
    TRY(strcmp("abc", "abb") > 0);
    TRY(strcmp("abc", "abcd") < 0);
    TRY(strcmp("abcd", "abc") > 0);
    TRY(strcmp("abc", "ab") > 0);
    TRY(strcmp("ab", "abc") < 0);
    TRY(strcmp("abc", "a") > 0);
    TRY(strcmp("a", "abc") < 0);
    TRY(strcmp("abc", "") > 0);
    TRY(strcmp("", "abc") < 0);
    TRY(strcmp("", "") == 0);
}

void test_strncmp(func_int_ptr strncmp, int *passed, int *totalTested)
{
    START_TEST_SUITE("strncmp");

    // Same as strcmp
    TRY(strncmp("abc", "abc", 4) == 0);
    TRY(strncmp("abc", "abd", 4) < 0);
    TRY(strncmp("abc", "abb", 4) > 0);
    TRY(strncmp("abc", "abcd", 4) < 0);
    TRY(strncmp("abcd", "abc", 4) > 0);
    TRY(strncmp("abc", "ab", 4) > 0);
    TRY(strncmp("ab", "abc", 4) < 0);
    TRY(strncmp("abc", "a", 4) > 0);
    TRY(strncmp("a", "abc", 4) < 0);
    TRY(strncmp("abc", "", 4) > 0);
    TRY(strncmp("", "abc", 4) < 0);
    TRY(strncmp("", "", 4) == 0);

    // Strncmp
    TRY(strncmp("abc", "abz", 2) == 0);
    TRY(strncmp("Hello world", "Hello world", 0) == 0);
    TRY(strncmp("Hello world", "Hello world", 1) == 0);
    TRY(strncmp("Hello world", "Hello world", 11) == 0);
    TRY(strncmp("Hello world", "Hello world", 12) == 0);
    TRY(strncmp("Hello world", "Hello world", 13) == 0);
    TRY(strncmp("Hello world", "abcd", 0) == 0);
    TRY(strncmp("Hello world", "Hello world", 32456) == 0);
}

void test_strcasecmp(func_int_ptr strcasecmp, int *passed, int *totalTested)
{
    START_TEST_SUITE("strcasecmp");

    // Same as strcmp
    TRY(strcasecmp("abc", "abc") == 0);
    TRY(strcasecmp("abc", "abd") < 0);
    TRY(strcasecmp("abc", "abb") > 0);
    TRY(strcasecmp("abc", "abcd") < 0);
    TRY(strcasecmp("abcd", "abc") > 0);
    TRY(strcasecmp("abc", "ab") > 0);
    TRY(strcasecmp("ab", "abc") < 0);
    TRY(strcasecmp("abc", "a") > 0);
    TRY(strcasecmp("a", "abc") < 0);
    TRY(strcasecmp("abc", "") > 0);
    TRY(strcasecmp("", "abc") < 0);
    TRY(strcasecmp("", "") == 0);

    // Strcasecmp: same tests, with random upper/lower case
    TRY(strcasecmp("abc", "abc") == 0);
    TRY(strcasecmp("Abc", "aBC") == 0);
    TRY(strcasecmp("aBC", "Abc") == 0);
    TRY(strcasecmp("AbC", "ABc") == 0);

    TRY(strcasecmp("A", "A") == 0);
    TRY(strcasecmp("abC", "abc") == 0);
    TRY(strcasecmp("ZeLlO, wOrLd %d%d ! ;)AAA", "zello, world %d%d ! ;)aaa") == 0);
    TRY(strcasecmp("zello, world %d%d ! ;)", "ZeLlO, wOrLd %d%d") > 0);
}

void test_strrchr(func_char_ptr rindex, int *passed, int *totalTested)
{
    START_TEST_SUITE("rindex");

    // Classic
    TRY(rindex("abc", 'a') == (char *)"abc");
    TRY(rindex("abca", 'b') == "abca" + 1);
    TRY(rindex("abca", 'c') == "abca" + 2);
    TRY(rindex("abca", 'd') == NULL);

    TRY(rindex("abaca", 'a') == "abaca" + 4);
    TRY(rindex("abbca", 'b') == "abbca" + 2);
    TRY(rindex("abcca", 'c') == "abcca" + 3);
    TRY(rindex("", 'd') == NULL);
    TRY(rindex("", 0) == (char *)"");
    TRY(rindex("aaaa", 0) == "aaaa" + 4);
    TRY(rindex("\0aaaa", 0) == (char *)"\0aaaa");
}

void test_strstr(func_char_ptr strstr, int *passed, int *totalTested)
{
    START_TEST_SUITE("strstr");

    TRY(strstr("abc", "a") == (char *)"abc");
    TRY(strstr("abca", "b") == "abca" + 1);
    TRY(strstr("abca", "c") == "abca" + 2);
    TRY(strstr("abca", "d") == NULL);
    TRY(strstr("Hello world", "lo wo") == (char *)"Hello world" + 3);
    TRY(strstr("Hello world", "Hello world") == (char *)"Hello world");
    TRY(strstr("Hello world", "Hello worlddd") == NULL);
    TRY(strstr("Hello hello world", "lo w") == "Hello hello world" + 9);
    TRY(strstr("abcd", "") == (char *)"abcd");
    TRY(strstr("", "abcd") == NULL);

}

void test_strpbrk(func_char_ptr strpbrk, int *passed, int *totalTested)
{
    START_TEST_SUITE("strpbrk");

    // Same as strchr
    TRY(strpbrk("abc", "a") == (char *)"abc");
    TRY(strpbrk("abc", "b") == "abc" + 1);
    TRY(strpbrk("abc", "c") == "abc" + 2);
    TRY(strpbrk("abc", "d") == NULL);
    TRY(strpbrk("abc", "") == 0);
    TRY(strpbrk("abc", "\1") == NULL);
    TRY(strpbrk("", "a") == NULL);
    TRY(strpbrk("", "") == 0);

    // Trickier
    TRY(strpbrk("Hello world", "zzzzzzzzzzzzzzzzzzzH") == (char *)"Hello world");
    TRY(strpbrk("Hello world", "zzzzzzzzzzzzzzzdzzzz") == (char *)"Hello world" + 10);
    TRY(strpbrk("Hello world", "zzzzzzzzzzzzzzzzzzz") == NULL);
    TRY(strpbrk("Hello world", "zzzzzzzzzz zzzzzzzzz") == (char *)"Hello world" + 5);
    TRY(strpbrk("Hello world", "zzzzzzzzzzzzzzzdezzzz") == (char *)"Hello world" + 1);
}

void test_strcspn(func_size_t_ptr strcspn, int *passed, int *totalTested)
{
    START_TEST_SUITE("strcspn");

    TRY(strcspn("abc", "a") == 0);
    TRY(strcspn("abc", "b") == 1);
    TRY(strcspn("abc", "c") == 2);
    TRY(strcspn("abc", "d") == 3);
    TRY(strcspn("abc", "") == 3);

    TRY(strcspn("Hello world", "zzzzzzzzzzzzzzzzzzzH") == 0);
    TRY(strcspn("Hello world", "zzzzzzzzzzzzzzzdzzzz") == 10);
    TRY(strcspn("Hello world", "zzzzzzzzzzzzzzzdzezz") == 1);
    TRY(strcspn("Hello world", "zzzzzzzzzzzzzzzzzzz") == 11);
}

void test_memfrob(func_ptr memfrob, int *passed, int *totalTested)
{
    START_TEST_SUITE("memfrob");

    {
    char str[] = "Hello world";
    char str2[] = "Hello world";
    memfrob(str2, 11);
    TRY(memfrob(str, 11) == str);
    TRY(memcmp(str, str2, 11) == 0);
    TRY(memfrob(str, 11) == str);
    TRY(memcmp(str, "Hello world", 11) == 0);
    }
    {
    char str[] = "";
    char str2[] = "";
    memfrob(str2, 1);
    TRY(memfrob(str, 1) == str);
    TRY(memcmp(str, str2, 1) == 0);
    TRY(memfrob(str, 1) == str);
    TRY(memcmp(str, "", 1) == 0);
    }
    {
    char str[] = "\42";
    char str2[] = "\42";
    memfrob(str2, 2);
    TRY(memfrob(str, 2) == str);
    TRY(memcmp(str, str2, 2) == 0);
    TRY(memfrob(str, 2) == str);
    TRY(memcmp(str, "\42", 2) == 0);
    }
    {
    char str[] = "";
    char str2[] = "";
    memfrob(str2, 0);
    TRY(memfrob(str, 0) == str);
    TRY(memcmp(str, str2, 1) == 0);
    TRY(memfrob(str, 0) == str);
    TRY(memcmp(str, "", 1) == 0);
    }
}

void test_index(func_char_ptr index, int *passed, int *totalTested)
{
    START_TEST_SUITE("index");

    test_strchr(index, passed, totalTested);
}

void test_rindex(func_char_ptr rindex, int *passed, int *totalTested)
{
    START_TEST_SUITE("rindex");

    test_strrchr(rindex, passed, totalTested);
}

void test_ffs(func_int_ptr ffs, int *passed, int *totalTested)
{
    START_TEST_SUITE("ffs");
    for (int i = 0; i < 10000000; i++) {
        TRY(ffs(i) == ffs(i));
    }
    for (int i = -10000000; i < 0; i++) {
        TRY(ffs(i) == ffs(i));
    }
    TRY(ffs(-1) == ffs(-1));
}
