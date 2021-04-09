# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 15:24:04 by amarini-          #+#    #+#              #
#    Updated: 2021/04/08 10:34:17 by amarini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_list_managment.c ft_str_managment.c \
		ft_data_managment.c ft_data_utils.c ft_print.c ft_conversions.c \
		ft_converts_utils.c ft_flags_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

convert: $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all convert
