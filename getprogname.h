#ifndef GETPROGNAME_H
#define GETPROGNAME_H

#include <stddef.h>

char *get_program_name(size_t n, char buf[static n]);
char *getprogname(void);

#endif
