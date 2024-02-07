#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <criterion/criterion.h>

#define CMP_CRASH_1(F, FP, A0) do {                   \
    int must_crash = 1;                               \
    pid_t pid = fork();                               \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(F(A0));                                \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        must_crash = WIFSIGNALED(status);             \
    }                                                 \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(FP(A0));                               \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        cr_assert(WIFSIGNALED(status) == must_crash); \
    }                                                 \
} while (0)

#define CMP_CRASH_2(F, FP, A0, A1) do {               \
    int must_crash = 1;                               \
    pid_t pid = fork();                               \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(F(A0, A1));                            \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        must_crash = WIFSIGNALED(status);             \
    }                                                 \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(FP(A0, A1));                           \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        cr_assert(WIFSIGNALED(status) == must_crash); \
    }                                                 \
} while (0)

#define CMP_CRASH_3(F, FP, A0, A1, A2) do {           \
    int must_crash = 1;                               \
    pid_t pid = fork();                               \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(F(A0, A1, A2));                        \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        must_crash = WIFSIGNALED(status);             \
    }                                                 \
    if (-1 == pid) {                                  \
        perror("fork");                               \
        _exit(1);                                     \
    }                                                 \
    if (0 == pid) {                                   \
        (void)(FP(A0, A1, A2));                       \
        _exit(0);                                     \
    } else {                                          \
        int status;                                   \
        waitpid(pid, &status, 0);                     \
        cr_assert(WIFSIGNALED(status) == must_crash); \
    }                                                 \
} while (0)

extern void *_memcpy(void *__restrict __dest, const void *__restrict __src, size_t __n);
extern void *_memmove(void *__dest, const void *__src, size_t __n);
extern void *_memset(void *__s, int __c, size_t __n);
extern int _strcmp(const char *__s1, const char *__s2);
extern int _strncmp(const char *__s1, const char *__s2, size_t __n);
extern char *_strchr(const char *__s, int __c);
extern char *_strrchr(const char *__s, int __c);
extern char *_strpbrk(const char *__s, const char *__accept);
extern char *_strstr(const char *__haystack, const char *__needle);
extern size_t _strlen(const char *__s);
