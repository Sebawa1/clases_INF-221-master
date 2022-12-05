#include <stdio.h>
#include <ctype.h>

#include "menu.h"

int menu(const char *prompt, const char *options)
{
	char c, opt;
	const char *p;

	printf("%s: ", prompt);
	for (;;) {
		while (isspace(c = getchar()))
			;
		if (c == EOF) {
			putchar('\n');
			return EOF;
		}
		opt = tolower(c);
		while ((c = getchar()) != EOF && c != '\n')
			;
		for (p = options; *p && opt != tolower(*p); p++)
			;
		if (*p)
			return opt;
		printf("%s: ", options);
	}
}
