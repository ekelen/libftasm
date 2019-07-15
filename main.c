/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:01 by ekelen            #+#    #+#             */
/*   Updated: 2019/07/14 20:58:04 by ekelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libfts.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>

#undef FAIL
#define FAIL "[FAIL]"
#undef SUCCESS
#define SUCCESS "[SUCCESS]"

#undef BOLD
#define BOLD "\x1b[1m"
#undef GREEN
#define GREEN "\x1b[32m"
#undef RED
#define RED "\x1b[91m"
#undef RESET
#define RESET "\x1b[0m"

#undef CHECK
#define CHECK "\xE2\x9C\x93"
#undef X
#define X "\xe2\x9c\x97"

typedef struct s_test t_test;
typedef struct s_test
{
	bool (*test_fn)(void);
	char const name[0x40];
} t_test;

static void run_test(t_test test)
{
	static int i = 0;
	bool passed = 0;
	dprintf(1, "\n%s%d: %s%s\n", BOLD, i, test.name, RESET);
	dprintf(1, "%s\n", test.name);
	passed = test.test_fn();
	if (passed)
	{
		dprintf(1, "\n%s%s%s\n", GREEN, SUCCESS, RESET);
	}
	else
	{
		dprintf(1, "\n%s%s%s\n", RED, FAIL, RESET);
	}
	i++;
}

// I. Required simple
bool	test_ft_isalpha(void) {
	return (true);
}
bool	test_ft_isdigit(void) {
	return (true);
}
bool	test_ft_isalnum(void) {
	return (true);
}
bool	test_ft_isascii(void) {
	return (true);
}
bool	test_ft_isprint(void) {
	return (true);
}
bool	test_ft_toupper(void) {
	return (true);
}
bool	test_ft_tolower(void) {
	return (true);
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

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

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

	for (int i = 0; i < 18; i++)
	{
		run_test(tests[i]);
	}

	printf("%s Nothing here yet... %s", BOLD, RESET);
}