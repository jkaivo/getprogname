getprogname
===========

This liblet includes two functions, `getprogname()` and `get_program_name()`.
The former is an implementation of the BSD function of the same name. The
latter is a variant that takes a buffer to fill along with its size as
arguments, rather than relying on a static variable. This makes it thread safe.

SYNOPSIS
========

    #include "getprogname.h"

    char *get_program_name(size_t n, char buf[static n]);
    char *getprogname(void);

DESCRIPTION
===========

These functions provide the current process's name as derived from the original
contents of `argv[0]`.

`getprogname()` returns a pointer to a static buffer, which may overwritten by
future calls to `getprogname()`.

`get_program_name()` will fill the buffer pointed to by `buf`, up to `n` bytes,
with the current process name. The declaration syntax requires a compiler
supporting at least C99, and allows the compiler to perform static analysis
on the size of `buf` to ensure that it is at least `n` bytes in size.

RETURN VALUE
============

On failure, both functions return `NULL`. On success, `getprogname()` returns
a pointer to a static buffer containing the current program name;
`get_program_name()` returns a pointer to `buf`.
