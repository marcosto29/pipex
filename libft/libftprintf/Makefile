# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 13:02:55 by matoledo          #+#    #+#              #
#    Updated: 2025/05/19 17:31:39 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

#PHONY is used when a target is not gonna create a file
#this way if smoehow anyfile is called like the target there are no problems
.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@rm -rf *.o

.PHONY: fclean
fclean:
	@rm -rf *.o *.a

.PHONY: re
re: fclean all