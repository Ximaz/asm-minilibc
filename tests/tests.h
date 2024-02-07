#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../functions.h"
#include <criterion/criterion.h>

#define CMP_CRASH_1(F, FP, A0) do {                           \
    int must_crash = 1;                                       \
    pid_t pid = fork();                                       \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(F(A0));                                        \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        must_crash = 0 != WIFSIGNALED(status);                \
    }                                                         \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(FP(A0));                                       \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        cr_assert(must_crash ? 0 != WIFSIGNALED(status) : 1); \
    }                                                         \
} while (0)

#define CMP_CRASH_2(F, FP, A0, A1) do {                       \
    int must_crash = 1;                                       \
    pid_t pid = fork();                                       \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(F(A0, A1));                                    \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        must_crash = 0 != WIFSIGNALED(status);                \
    }                                                         \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(FP(A0, A1));                                   \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        cr_assert(must_crash ? 0 != WIFSIGNALED(status) : 1); \
    }                                                         \
} while (0)

#define CMP_CRASH_3(F, FP, A0, A1, A2) do {                   \
    int must_crash = 1;                                       \
    pid_t pid = fork();                                       \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(F(A0, A1, A2));                                \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        must_crash = 0 != WIFSIGNALED(status);                \
    }                                                         \
    if (-1 == pid) {                                          \
        perror("fork");                                       \
        _exit(1);                                             \
    }                                                         \
    if (0 == pid) {                                           \
        (void)(FP(A0, A1, A2));                               \
        _exit(0);                                             \
    } else {                                                  \
        int status;                                           \
        waitpid(pid, &status, 0);                             \
        cr_assert(must_crash ? 0 != WIFSIGNALED(status) : 1); \
    }                                                         \
} while (0)
