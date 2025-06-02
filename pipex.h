/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:34:42 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/02 10:19:07 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"
# include "libft/libftget_next_line/libftget_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

void	fd_errors(int fdi, int fdo, char *argvi, char *argvo);
char	*last_string(char **ds);
int		here_doc_parse(char **argv);
char	**ft_split_pipex(char const *s, char c);
int		is_empty(char *s);
void	free_memory(char **splitted_word);

#endif