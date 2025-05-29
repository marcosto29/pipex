# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 16:09:09 by matoledo          #+#    #+#              #
#    Updated: 2025/05/29 18:57:41 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd_r.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd_b_r.c \
	ft_putnbr_fd_b.c \
	ft_putnbr_fd_r.c \
	ft_putnbr_fd.c \
	ft_putstr_fd_r.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

#Finds all the .c files and substitute the final .c for .o with
#what this is saying is: OBJS is the list of SRCS but with .o instead of .c
OBJS = $(SRCS:.c=.o)

DIRS = ./libftprintf \
		./libftget_next_line \

all: $(NAME)

#when creating the library access each of the subdirectories and create it respectives libraries
#this way each function can have its own .a
#	for dir in $(DIRS); do \
		$(MAKE) -C $$dir all; \
		ar -rcs $(NAME) $$dir/*.o; \
	done

$(NAME): $(OBJS)
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir all; \
		ar -rcs $(NAME) $$dir/*.o; \
	done
	@ar -rcs $(NAME) $(OBJS)

#when the makefile tries to access the .o files but doesn't finds them is gonna search for a rule to create them
#this is that rule
#$< refers to the first parameter in this case %.c (what is at the right of the :)
%.o : %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	@rm -rf *.o

fclean: clean
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
	@rm -rf *.a

#when re, the fclean and all target are executed
re: fclean all
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir re; \
	done