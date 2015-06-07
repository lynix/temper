/* Copyright 2015 Alexander Koch <lynix47@gmail.com>
 *
 * This file is part of 'temper'.
 *
 * 'temper' is distributed under the MIT License, see LICENSE file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "../../libtemper1/include/libtemper1.h"


void err_exit(const char *format, ...);


int main(int argc, char *argv[])
{
	char *err = NULL;

	double temp = temper1_read(&err);
	if (err != NULL)
		err_exit("%s", err);

	printf("%.1f\n", temp);

	return EXIT_SUCCESS;
}


void err_exit(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	fflush(stderr);
	va_end(args);

	exit(EXIT_FAILURE);
}
