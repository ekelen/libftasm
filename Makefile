# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekelen <ekelen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 14:12:17 by ekelen            #+#    #+#              #
#    Updated: 2019/07/14 21:00:34 by ekelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
CC = nasm

# MANDATORY

SRCS += ft_bzero.s
SRCS += ft_cat.s
SRCS += ft_isalnum.s
SRCS += ft_isalpha.s
SRCS += ft_isascii.s
SRCS += ft_isdigit.s
SRCS += ft_isprint.s
SRCS += ft_memcpy.s
SRCS += ft_memset.s
SRCS += ft_puts.s
SRCS += ft_strcat.s
SRCS += ft_strdup.s
SRCS += ft_strlen.s
SRCS += ft_tolower.s
SRCS += ft_toupper.s

# BONUS

SRCS += ft_memcmp.s
SRCS += ft_strcmp.s
SRCS += ft_strcpy.s
SRCS += ft_strequ.s
SRCS += ft_strchr.s


OBJ_DIR = obj

OBJS = $(patsubst %.s, obj/%.o, $(SRCS))

ASFLAGS = -f macho64
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)

obj/%.o: $(addprefix src/, %.s)
	@$(CC) -o $@ $(ASFLAGS) $^

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test:
	@rm -f a.out
	@gcc $(CFLAGS) main.c libfts.a


.phony: clean re fclean

clean:
	@rm -rf obj a.out

fclean: clean
	@rm -rf obj
	@rm -f $(NAME)

re: fclean all