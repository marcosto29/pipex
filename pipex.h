/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:34:42 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/29 20:37:19 by matoledo         ###   ########.fr       */
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

void	free_memory(char **s);
char	*last_string(char **ds);
char	**add_string(char **ds, char *s);
size_t	ft_strlen_double(char **ds);
char	*last_string(char **ds);

#endif