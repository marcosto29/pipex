/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 23:20:20 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen_double(char **s)
{
	int	size;

	size = 0;
	while(*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	**ft_strdup_double(char **s)
{
	int	size;
	char	**pt_return;
	char	**pt_aux;

	pt_return = ft_calloc(sizeof(char *), ft_strlen_double(s) + 1);
	pt_aux = pt_return;
	while(*s)
		*pt_aux++ = *s++;
	return(pt_return);
}

//pequeño parse de los comandos
int	command_parse(char **s)
{
	while (*s)
	{
		if (ft_strlen(*s) <= 1)
			return (-1);
		if (**s != '-')
			return (-1);
		s++;
	}
	return (0);
}