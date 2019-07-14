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

# define FAIL "[FAIL]"
# define SUCCESS "[SUCCESS]"

# define RESET "\x1b[0m"
# define RED "\x1b[91m"
# define CHECK "\xE2\x9C\x93"
# define GREEN "\x1b[32m"
# define BOLD "\x1b[1m"

int		main(int ac, char **av) {
	printf("%s Nothing here yet... %s", BOLD, RESET);
}