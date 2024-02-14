#pragma once
#include <stdlib.h>

extern void *_memcpy(void *__restrict __dest, const void *__restrict __src, size_t __n);
extern void *_memmove(void *__dest, const void *__src, size_t __n);
extern void *_memset(void *__s, int __c, size_t __n);
extern char *_rindex(const char *s, int c);
extern int _strcasecmp(const char *s1, const char *s2);
extern char *_strchr(const char *__s, int __c);
extern char *_index(const char *__s, int __c);
extern int _strcmp(const char *__s1, const char *__s2);
extern size_t _strcspn(const char *s, const char *reject);
extern size_t _strlen(const char *__s);
extern int _strncmp(const char *__s1, const char *__s2, size_t __n);
extern char *_strpbrk(const char *__s, const char *__accept);
extern char *_strrchr(const char *__s, int __c);
extern char *_strstr(const char *__haystack, const char *__needle);
extern int _ffs(int value);
