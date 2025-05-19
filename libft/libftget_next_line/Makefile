# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 13:06:26 by matoledo          #+#    #+#              #
#    Updated: 2025/05/19 17:31:50 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftget_next_line.a

SRCS = ft_get_next_line.c \

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