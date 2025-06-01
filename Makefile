# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:13:30 by matoledo          #+#    #+#              #
#    Updated: 2025/06/01 13:19:54 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRCS= pipex.c \
	pipex_utils.c \
	ft_split_pipex.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft all
	@$(CC) -o $(NAME) $(OBJS) -L./libft -l:libft.a

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	$(MAKE) -C ./libft clean
	@rm -rf *.o

fclean: clean
	$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) -C ./libft re