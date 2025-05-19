/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:34:42 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 23:16:21 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"
# include <stdio.h>

int		ft_strlen_double(char **c);
char	**ft_strdup_double(char **s);
int		command_parse(char **s);

#endif