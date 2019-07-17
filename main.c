/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:01 by ekelen            #+#    #+#             */
/*   Updated: 2019/07/17 17:39:33 by ekelen           ###   ########.fr       */
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
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_isalpha(test_case) == isalpha(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_isdigit(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_isdigit(test_case) == isdigit(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_isalnum(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_isalnum(test_case) == isalnum(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_isascii(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_isascii(test_case) == isascii(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_isprint(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_isprint(test_case) == isprint(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_toupper(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_toupper(test_case) == toupper(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_tolower(void) {
	bool success = true;

	for (int test_case = -1; test_case < UCHAR_MAX; test_case++) {
		if (ft_tolower(test_case) == tolower(test_case)) {
			g_verbose && dprintf(2, "%s %s char %lc (%#x)%s\n", GREEN, CHECK, (char)test_case, (int16_t)test_case, RESET);
		} else {
			g_verbose && dprintf(2, "%s %s char %c q(%#x)%s\n", RED, X, (char)test_case, (int16_t)test_case, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_bzero(void) {
	// TODO: Music Falls Around Her
	bool success = true;
	const size_t N_CASES = 7, BUFLEN = 300;
	char copy_buf[BUFLEN] = "", buf[BUFLEN] = "";
	size_t len;
	char test_case[][BUFLEN] = {
		"",
		"\0",
		"Hi",
		"Bye",
		"École 42",
		"érable 🍁",
		"The Road goes ever on and on, / Down from the door where it began. / Now far ahead the Road has gone, / And I must follow, if I can, / Pursuing it with eager feet, / Until it joins some larger way / Where many paths and errands meet. / And whither then? I cannot say."
	};


	for (size_t i = 0; i < N_CASES; i++) {
		bzero(buf, BUFLEN);
		bzero(copy_buf, BUFLEN);
		strcpy(buf, test_case[i]);
		strcpy(copy_buf, test_case[i]);

		len = strlen(test_case[i]);
		bzero(test_case[i], len);
		ft_bzero(copy_buf, len);

		if (!memcmp(test_case[i], copy_buf, BUFLEN)) {
			g_verbose && dprintf(1, "%s %s %s %s\n", GREEN, CHECK, buf, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s %s %s\n", RED, X, buf, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_puts(void) {
	const size_t N_CASES = 6;
	int actual, expected;
	bool success = true;
	const char *cases[] = {
		NULL, // TODO: Do we care about printing (null)
		"\\200",
		"",
		"abc",
		"Érable 🍁",
		"The Road goes ever on and on, / Down from the door where it began. / Now far ahead the Road has gone, / And I must follow, if I can, / Pursuing it with eager feet, / Until it joins some larger way / Where many paths and errands meet. / And whither then? I cannot say."
	};

	for (size_t i = 0; i < N_CASES; i++) {
		actual = ft_puts(cases[i]);
		expected = puts(cases[i]);
		if (actual == expected) {
			g_verbose && dprintf(1, "%s %s %s\n", GREEN, CHECK, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s expected: %d, got: %d%s\n", RED, X, expected, actual, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_strcat(void) {
	const size_t N_CASES = 7, BUFLEN = 300;
	char actual[BUFLEN] = "", expected[BUFLEN] = "";
	bool success = true;
	char const *s1[BUFLEN] = {
		"1 + 1",
		"0 characters are appended to me!",
		"",
		"abc",
		"Érable 🍁 ",
		"The Road goes ever on and on, / Down from the door where it began. / Now far ahead the Road has gone, / And I must follow, if I can, / Pursuing it with eager feet, / Until it joins some larger way / Where many paths and errands meet. / And whither then? I cannot say."
	};

	char const *s2[BUFLEN] = {
		" = 2\n",
		"",
		"I'm appended to 0 characters!\n",
		"def\n",
		" Sapin 🌲\n",
		" -- JRR Tolkien\n",
	};

	for (size_t i = 0; i < N_CASES - 2; i++) {
		bzero(actual, BUFLEN);
		bzero(expected, BUFLEN);

		strcpy(actual, s1[i]);
		strcpy(expected, s1[i]);

		ft_strcat(actual, s2[i]);
		strcat(expected, s2[i]);

		if (!strcmp(actual, expected)) {
			g_verbose && dprintf(1, "%s %s got expected: %s %s\n", GREEN, CHECK, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s expected: %s, got: %s%s\n", RED, X, expected, actual, RESET);
			success = false;
		}
	}
	return (success);
}

// II. Required less simple
bool	test_ft_strlen(void) {
	bool success = true;
	const size_t N_CASES = 7;

	const char *cases[] = {
		"123456789",
		"123",
		"",
		"🇨🇦",
		"Ensoleillé 🌞",
		"Ho! Tom Bombadil, Tom Bombadillo! / By water, wood and hill, by the reed and willow, / By fire, sun and moon, harken now and hear us! / Come, Tom Bombadil, for our need is near us!",
		"String\0 Interrupted"
	};

	for (size_t i = 0; i < N_CASES; i++) {
		if (ft_strlen(cases[i]) == strlen(cases[i])) {
			g_verbose && dprintf(1, "%s %s got expected strlen: %ld for string: %s%s\n", GREEN, CHECK, ft_strlen(cases[i]), cases[i], RESET);
		} else {
			g_verbose && dprintf(1, "%s %s got: %ld, expected: %ld\nstring: %s%s\n", RED, X, ft_strlen(cases[i]), strlen(cases[i]), cases[i], RESET);
			success = false;
		}
	}
	return (success);
}

bool	_test_ft_strdup(bool success, const char *s1) {
	char *actual = NULL, *expected = NULL;
	size_t diff;

	actual = ft_strdup(s1);
	expected = strdup(s1);

	if ((diff = strcmp(actual, expected)) == 0) {
			g_verbose && dprintf(1, "%s %s duplicated string: %s%s\n", GREEN, CHECK, s1, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s failed duplicate: %s\nexpected 0 diff, got: %ld%s\n\n", RED, X, s1, diff, RESET);
			success = false;
	}
	free(actual);
	free(expected);
	return (success);
}

bool	test_ft_strdup(void) {
	// TODO: Info re unexpected bvr. strdup(NULL) segfault.
	bool success = true;

	// basic tests
	const size_t N_BASIC_CASES = 7;
	char *case_basic[] = {
		"",
		"🇨🇦",
		"↓↑",
		"String\0 Interrupted",
		"abcdefghijklmnopqrstuvwxyz",
		"Érable",
		"All that is gold does not glitter, / Not all those who wander are lost; \
			/ The old that is strong does not wither, / Deep roots are not reached by the frost. \
			/ From the ashes a fire shall be woken, / A light from the shadows shall spring; \
			/ Renewed shall be blade that was broken, / The crownless again shall be king."
	};
	for (size_t i = 0; i < N_BASIC_CASES; i++) {
		success = _test_ft_strdup(success, case_basic[i]);
	}

	// Long strings
	char *long_str = (char *)malloc(BUFSIZ * sizeof(char));

	memset(long_str, 'x', BUFSIZ - 1);
	long_str[BUFSIZ - 1] = 0;
	success = _test_ft_strdup(success, long_str);

	long_str[0] = 0;
	success = _test_ft_strdup(success, long_str);

	long_str = realloc(long_str, BUFSIZ * 10);
	memset(long_str, '.', (BUFSIZ * 10));
	long_str[(BUFSIZ * 10) - 1] = 0;
	success = _test_ft_strdup(success, long_str);

	free(long_str);
	return (success);
}

struct s_memset_case {
	void		*s;
	int			c;
	size_t	len;
};

bool	test_ft_memset(void) {
	const size_t N_CASES = 5;
	bool success = true;
	char *buf = NULL, *buf_mine = NULL;

	struct s_memset_case mcases[] = {
		{"abcdefghijklmnopqrstuvwxyz", 'X', 0},
		{"abcdefghijklmnopqrstuvwxyz", 'X', 4},
		{"abcdefghijklmnopqrstuvwxyz", '\0', 1},
		{"àéîöœü", 'X', 4},
		{"abcdefghijklmnopqrstuvwxyz", 'X', 26}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		buf = strdup(mcases[i].s);
		buf_mine = strdup(mcases[i].s);
		memset((void *)buf, mcases[i].c, mcases[i].len);
		ft_memset((void *)buf_mine, mcases[i].c, mcases[i].len);
		if (!strcmp(buf, buf_mine)) {
			g_verbose && dprintf(1, "%s %s set memory: %s %s\n", GREEN, CHECK, buf_mine, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s expected: %s, got: %s%s\n", RED, X, buf, buf_mine, RESET);
			success = false;
		}
		free(buf);
		free(buf_mine);
		buf = NULL, buf_mine = NULL;
	}
	return (success);
}

struct s_memcpy_case {
	size_t			bufsize;
	const char	*dstcontent;
	const char	*src;
	size_t			n;
};

bool	test_ft_memcpy(void) {
	const size_t N_CASES = 7;
	bool success = true;
	char *buf = NULL, *buf_mine = NULL;

	struct s_memcpy_case cases[] = {
		{27, "00000000000000000000000000", "abcdefghijklmnopqrstuvwxyz", 27},
		{27, "00000000000000000000000000", "abcdefghijklmnopqrstuvwxyz", 5},
		{27, "00000000000000000000000000", "abcdefghijklmnopqrstuvwxyz", 25},
		{27, "00000000000000000000000000", "abcdefghijklmnopqrstuvwxyz", 1},
		{27, "00000000000000000000000000", "åéîØü", 10},
		{5, NULL, "åé", 5},
		{5, NULL, "\0\0\0\0\0", 1}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		buf = realloc(buf_mine, cases[i].bufsize);
		buf_mine = realloc(buf_mine, cases[i].bufsize);
		if (cases[i].dstcontent != NULL) {
			strcpy(buf, cases[i].dstcontent);
			strcpy(buf_mine, cases[i].dstcontent);
		}
		memcpy((void *)buf, cases[i].src, cases[i].n);
		ft_memcpy((void *)buf_mine, cases[i].src, cases[i].n);
		if (!memcmp(buf, buf_mine, cases[i].n)) {
			g_verbose && dprintf(1, "%s %s copied: %s into %s (addr: %p), got %s %s\n", GREEN, CHECK, cases[i].src, cases[i].dstcontent, buf_mine, buf_mine, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s expected: %s, got: %s%s\n", RED, X, buf, buf_mine, RESET);
			success = false;
		}
		free(buf);
		free(buf_mine);
		buf = NULL, buf_mine = NULL;
	}
	return (success);
}

// III. Required ft_cat
bool	test_ft_cat(void) {
	int fd, success = true;
	const char *path = "auteur";

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		ft_cat(fd);
		close(fd);
	} else {
		dprintf(2, "%s Error opening file: %s %s", RED, strerror(errno), RESET);
	}
	return (success);
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
