#define _POSIX_C_SOURCE 2
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *get_program_name(size_t n, char buf[static n])
{
	char cmd[_POSIX_ARG_MAX];
	snprintf(cmd, sizeof(cmd), "ps -p %ld -o comm=", (long)getpid());

	FILE *pip = popen(cmd, "r");
	if (pip == NULL) {
		return NULL;
	}

	char *ret = fgets(pip, buf, n);
	if (ret) {
		char *nl = strchr(ret, '\n');
		if (nl) {
			*nl = '\0';
		}
	}

	pclose(pip);
	return ret;
}

char *getprogname(void)
{
	static char progname[_POSIX_NAME_MAX];
	return get_program_name(sizeof(progname), progname);
}
