/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:34:42 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/31 18:11:33 by matoledo         ###   ########.fr       */
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

char	*last_string(char **ds);
char	**ft_split_pipex(char const *s, char c);
int		is_empty(char *s);
void	free_memory(char **splitted_word);

#endif