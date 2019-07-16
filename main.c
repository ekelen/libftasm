/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:01 by ekelen            #+#    #+#             */
/*   Updated: 2019/07/16 16:33:33 by ekelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libfts.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define FAIL "[FAIL]"
#define SUCCESS "[SUCCESS]"

#define BOLD "\x1b[1m"
#define GREEN "\x1b[32m"
#define RED "\x1b[91m"
#undef RESET
#define RESET "\x1b[0m"

#define CHECK "\xE2\x9C\x93"
#define X "\xe2\x9c\x97"

bool g_verbose = false;

typedef struct s_test
{
	bool (*test_fn)(void);
	char const name[0x40];
} t_test;

static void run_test(t_test test)
{
	static int i = 0;
	bool passed = 0;
	dprintf(1, "\n%s*----------------------------------*\n%02d. %s\n*----------------------------------*%s\n", BOLD, i, test.name, RESET);

	passed = test.test_fn();
	if (passed)
	{
		dprintf(1, "\n%s%02d. %-14s%18s%s\n", GREEN, i, test.name, SUCCESS, RESET);
		dprintf(1, "%s*----------------------------------*\n%s", GREEN, RESET);
	}
	else
	{
		dprintf(1, "\n%s%02d. %-14s%18s%s\n", RED, i, test.name, FAIL, RESET);
		dprintf(1, "%s*----------------------------------*\n%s", RED, RESET);
	}
	i++;
}

// I. Required simple
bool	test_ft_isalpha(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_isalpha(test_case) == isalpha(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}

bool	test_ft_isdigit(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_isdigit(test_case) == isdigit(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}
bool	test_ft_isalnum(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_isalnum(test_case) == isalnum(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}
bool	test_ft_isascii(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_isascii(test_case) == isascii(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}

bool	test_ft_isprint(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_isprint(test_case) == isprint(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}

bool	test_ft_toupper(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_toupper(test_case) == toupper(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}

bool	test_ft_tolower(void) {
	bool success = false;
	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if ((success = ft_tolower(test_case) == tolower(test_case)) == true) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
		}
	}
	return (success);
}
bool	test_ft_bzero(void) {
	return (true);
}
bool	test_ft_puts(void) {
	return (true);
}
bool	test_ft_strcat(void) {
	return (true);
}

// II. Required less simple
bool	test_ft_strlen(void) {
	return (true);
}
bool	test_ft_strdup(void) {
	return (true);
}
bool	test_ft_memset(void) {
	return (true);
}
bool	test_ft_memcpy(void) {
	return (true);
}

// III. Required ft_cat
bool	test_ft_cat(void) {
	return (true);
}

// IV. Bonus

bool	test_ft_memcmp(void) {
	return (true);
}
bool	test_ft_strcmp(void) {
	return (true);
}
bool	test_ft_strcpy(void) {
	return (true);
}
bool	test_ft_strequ(void) {
	return (true);
}
bool	test_ft_strchr(void) {
	return (true);
}

int main(int ac, char *av[]) {

	t_test tests[20] = {
		// I. Required simple
		{test_ft_isalpha, "ft_isalpha"},
		{test_ft_isdigit, "ft_isdigit"},
		{test_ft_isalnum, "ft_isalnum"},
		{test_ft_isascii, "ft_isascii"},
		{test_ft_isprint, "ft_isprint"},
		{test_ft_toupper, "ft_toupper"},
		{test_ft_tolower, "ft_tolower"},
		{test_ft_bzero, "ft_bzero"},
		{test_ft_puts, "ft_puts"},
		{test_ft_strcat, "ft_strcat"},

		// II. Required/less simple
		{test_ft_strlen, "ft_strlen"},
		{test_ft_strdup, "ft_strdup"},
		{test_ft_memset, "ft_memset"},
		{test_ft_memcpy, "ft_memcpy"},

		// III. Required ft_cat
		{test_ft_cat, "ft_cat"},

		// IV. BONUS
		{test_ft_memcmp, "ft_memcmp"},
		{test_ft_strcmp, "ft_strcmp"},
		{test_ft_strcpy, "ft_strcpy"},
		{test_ft_strequ, "ft_strequ"},
		{test_ft_strchr, "ft_strchr"}
	};

	if (ac > 1 && (!strcmp(av[1], "--verbose") || (!strcmp(av[1], "-v"))))
		g_verbose = true;
	if (ac > 1 + (int)g_verbose) {
		for (int a = 1; a < ac; a++) {
			dprintf(1, "av[a] :: %s\n", av[a]);
			for (int j = 0; j < 20; j++) {
				if (!strcmp(tests[j].name, av[a])) {
					run_test(tests[j]);
				}
			}
		}
	} else {
		for (int i = 0; i < 20; i++)
		{
			run_test(tests[i]);
		}
	}
	return (0);
}
