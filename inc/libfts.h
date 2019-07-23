/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:33:07 by ekelen            #+#    #+#             */
/*   Updated: 2019/07/14 21:01:23 by ekelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <stdlib.h>

/*
** I. Mandatory simple
*/

char      *ft_strcat(char *s1, const char *s2);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_puts(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
void      ft_bzero(void *s, size_t n);

/*
** II. Mandatory/less simple
*/

char		*ft_strdup(const char *s1);
size_t    ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);

/*
** III. Mandatory/ft_cat
*/

void		ft_cat(int fd);

/*
** IV. Bonus
*/

char		*ft_strcpy(char *dst, const char *src);
void		*ft_memalloc(size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
char      *ft_strchr(const char *s, int c);

#endif
