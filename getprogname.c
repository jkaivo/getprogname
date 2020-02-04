#define _POSIX_C_SOURCE 2
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

char *get_program_name(size_t n, char buf[static n])
{
	char cmd[_POSIX_ARG_MAX];
	snprintf(cmd, sizeof(cmd), "ps -p %ld -o comm=", (long)getpid());

	FILE *pip = popen(cmd, "r");
	if (pip == NULL) {
		return NULL;
	}

	if (fscanf(pip, "%s", buf) != 1) {
		pclose(pip);
		return NULL;
	}

	pclose(pip);
	return buf;
}

char *getprogname(void)
{
	static char progname[_POSIX_NAME_MAX];
	return get_program_name(sizeof(progname), progname);
}
