/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:01 by ekelen            #+#    #+#             */
/*   Updated: 2019/07/17 23:07:40 by ekelen           ###   ########.fr       */
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
#define RESET "\x1b[0m"

#define CHECK "\xE2\x9C\x93"
#define X "\xe2\x9c\x97"

#define N_FUNCTIONS 20

bool g_verbose = false;

typedef struct s_test
{
	bool (*test_fn)(void);
	char const name[0x40];
} t_test;

static bool run_test(t_test test)
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
	return (passed);
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

bool	_test_ft_bzero(void *expected, void *actual, size_t size, bool success) {
	if ((bool)expected ^ (bool)actual) {
		g_verbose && dprintf(1, "%s%s fail on %zu bytes%s\n", RED, X, size, RESET);
		return false;
	} else if (expected && actual && size > 0 && memcmp(actual, expected, size)) {
		g_verbose && dprintf(1, "%s%s fail on %zu bytes%s\n", RED, X, size, RESET);
		printf("fail memcmp\n");
		return false;
	} else {
		g_verbose && dprintf(1, "%s%s success on %zu bytes%s\n", GREEN, CHECK, size, RESET);
		return success;
	}
}

bool	test_ft_bzero(void) {
	char *actual = NULL, *expected = NULL;
	bool success = true;
	size_t N_CASES = 8;
	size_t cases[] = {0, 5, UINT64_MAX, 1, 10, 255, UINT16_MAX + UINT32_MAX, 8};
	for (size_t i = 0; i < N_CASES; i++) {
		expected = malloc(sizeof(char) * cases[i]);
		if (expected) bzero(expected, cases[i]);
		actual = malloc(sizeof(char) * cases[i]);
		if (actual) ft_bzero(actual, cases[i]);
		success = _test_ft_bzero(expected, actual, cases[i], success);

		if (actual) free(actual);
		if (expected) free(expected);
		actual = NULL, expected = NULL;
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
		if (!(actual | expected) || (actual>>31 == expected>>31)) { // same sign or both zero
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

	free(long_str);

	long_str = (char *)malloc(BUFSIZ * 10);
	memset(long_str, '.', (BUFSIZ * 10));
	long_str[(BUFSIZ * 10) - 1] = 0;
	success = _test_ft_strdup(success, long_str);

	free(long_str);
	return (success);
}

struct s_memset_case {
	void		*s;
	int			c;
	size_t		len;
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
	const char		*dstcontent;
	const char		*src;
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
	const char *path = "auteur";		// replace me with a valid file

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
struct s_memcmp_case {
	const void	*s1;
	const void	*s2;
	size_t				n;
};

bool	test_ft_memcmp(void) {
	bool success = true;
	const size_t N_CASES = 8;
	struct s_memcmp_case *kase = NULL;
	int actual, expected;
	struct s_memcmp_case cases[] = {
		{"Hello", "Goodbye", 5},
		{"\0", "\200", 1},
		{"\200", "\200", 1},
		{"école 42", "ecole 42", 8},
		{"", "123", 1},
		{"42 school", "21 school", 1},
		{"1234", "1234", 4},
		{"", "", 1}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		kase = &(cases[i]);
		expected = memcmp(kase->s1, kase->s2, kase->n);
		actual = ft_memcmp(kase->s1, kase->s2, kase->n);

		if (actual == expected) {
			g_verbose && dprintf(1, "%s %s cmp %ld bytes: (%s) (%s): expected: %d, got: %d%s\n", GREEN, CHECK, kase->n, kase->s1, kase->s2, expected, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s cmp %ld bytes: (%s) (%s): expected: %d, got: %d%s\n", RED, X, kase->n, kase->s1, kase->s2, expected, actual, RESET);
			success = false;
		}
	}
	return (success);
}

bool	test_ft_strcmp(void) {
	bool success = true;
	const size_t N_CASES = 7;
	struct s_memcmp_case *kase = NULL;
	int actual = 0, expected = 0;
	struct s_memcmp_case cases[] = {
		{"\0", "\200", 0}, // cmp 0, 128
		{"Hello", "Goodbye", 0},
		{"Goodbye", "Hello", 0},
		{"école 42", "ecole 42", 0},
		{"", "123", 0},
		{"42 school", "21 school", 0},
		{"1234", "1234", 0},
		{"", "", 0}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		kase = &(cases[i]);
		expected = strcmp(kase->s1, kase->s2);
		actual = ft_strcmp(kase->s1, kase->s2);

		if (actual == expected) {
			g_verbose && dprintf(1, "%s %s cmp (%s) (%s): expected: %d, got: %d%s\n", GREEN, CHECK, kase->s1, kase->s2, expected, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s cmp (%s) (%s): expected: %d, got: %d%s\n", RED, X, kase->s1, kase->s2, expected, actual, RESET);
			success = false;
		}
	}
	return (success);
}

struct s_strcpy {
	char *dst;
	const char *src;
};

bool	test_ft_strcpy(void) {
	bool success = true;
	const size_t N_CASES = 7;
	struct s_strcpy *kase = NULL;
	char *actual = NULL, *expected = NULL;
	struct s_strcpy cases[] = {
		{"....", "1234"},
		{"..........", "{[(˚˚)]}"},
		{"0123456789abcdef", "----------"},
		{"", ""},
		{"hello world", "\0"},
		{"!!", "é"},
		{"abc...", "abcdef"}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		kase = &(cases[i]);
		actual = strdup(kase->dst);
		expected = strdup(kase->dst);

		strcpy(expected, kase->src);
		ft_strcpy(actual, kase->src);

		if (!strcmp(actual, expected)) {
			g_verbose && dprintf(1, "%s %s copied %s into %s, got %s%s\n", GREEN, CHECK, kase->src, kase->dst, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s copied %s into %s, expected: %s, got %s%s\n", RED, X, kase->src, kase->dst, expected, actual, RESET);
			success = false;
		}
		free(actual);
		free(expected);
		actual = NULL, expected = NULL;
	}
	return (success);
}

bool	test_ft_strequ(void) {
	bool success = true;
	const size_t N_CASES = 9;
	struct s_memcmp_case *kase = NULL;
	int actual = -1, expected = -1;
	struct s_memcmp_case cases[] = {
		{"Hello", "Goodbye", 0},
		{"\200", "\200", 0},
		{"\200", "\0", 0},
		{"école 42", "ecole 42", 0},
		{"", "123", 0},
		{"42 school", "21 school", 0},
		{"1234", "1234", 0},
		{"", "", 0},
		{"12345", "1234", 0}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		kase = &(cases[i]);
		expected = strcmp(kase->s1, kase->s2) == 0;
		actual = ft_strequ(kase->s1, kase->s2);
		if (actual == expected) {
			g_verbose && dprintf(1, "%s %s cmp (%s) (%s): %d%s\n", GREEN, CHECK, kase->s1, kase->s2, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s cmp (%s) (%s): expected: %d, got: %d%s\n", RED, X, kase->s1, kase->s2, actual, expected, RESET);
			success = false;
		}
	}
	return (success);
}

struct s_strchr_case {
	const char *s;
	int c;
};

bool	test_ft_strchr(void) {
	bool success = true;
	const size_t N_CASES = 7;
	struct s_strchr_case *kase = NULL;
	char *actual = NULL, *expected = NULL;
	struct s_strchr_case cases[] = {
		{"12345", '5'},
		{"12345", '1'},
		{"12345", '0'},
		{"12345", 'X'},
		{"12345", '\0'},
		{"xxxxxxxxx\00", '0'},
		{"\0ooooooo0", '\0'}
	};

	for (size_t i = 0; i < N_CASES; i++) {
		kase = &(cases[i]);
		expected = strchr(kase->s, kase->c);
		actual = ft_strchr(kase->s, kase->c);
		if (actual == expected) {
			g_verbose && dprintf(1, "%s %s string search ('%c') in (%s): (%s)%s\n", GREEN, CHECK, (char)kase->c, kase->s, actual, RESET);
		} else {
			g_verbose && dprintf(1, "%s %s string search ('%c') in (%s): expected (%s) (%p), got (%s) (%p) %s\n", RED, X, (char)kase->c, kase->s, expected, expected, actual, actual, RESET);
			success = false;
		}
	}
	return (success);
}

int main(int ac, char *av[]) {
	size_t n_tests = 0;
	size_t n_success = 0;
	bool found_arg = false;

	t_test tests[N_FUNCTIONS] = {
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

	if (ac > 1 && (!strcmp(av[1], "--verbose") || (!strcmp(av[1], "-v")))) g_verbose = true;
	if (ac > 1 + (int)g_verbose && (!strcmp(av[1+(int)g_verbose], "--help") || (!strcmp(av[1+(int)g_verbose], "-h")))) {
		printf("Usage: $ ./a.out [-v|--verbose] [function names...]");
		return (0);
	}
	if (ac > 1 + (int)g_verbose) {
		for (int a = 1 + (int)g_verbose; a < ac; a++) {
			found_arg = false;
			for (int j = 0; j < N_FUNCTIONS; j++) {
				if (!strcmp(tests[j].name, av[a])) {
					n_success += run_test(tests[j]);
					n_tests++;
					found_arg = true;
				}
			}
			if (!found_arg) {
				printf("\n%sarg %s not recognized%s\n", RED, av[a], RESET);
			}
		}
	} else {
		for (int i = 0; i < N_FUNCTIONS; i++)
		{
			n_success += run_test(tests[i]);
			n_tests++;
		}
	}
	dprintf(1, "\n%s*----------------------------------*\n", BOLD);
	dprintf(1, "        🏁  Finished! 🏁\n\n");
	dprintf(1, "TESTS SUCCEEDED: %ld/%ld\n", n_success, n_tests);
	dprintf(1, "*----------------------------------*%s\n", RESET);
	return (0);
}
