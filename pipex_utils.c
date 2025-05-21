/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/21 14:03:30 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen_double(char **s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	**ft_strdup_double(char **src)
{
	char	**pt_return;
	char	**pt_aux;
	size_t	len;

	len = (int)ft_strlen_double(src);
	pt_return = ft_calloc(sizeof(char *), len + 1);
	if (!pt_return)
		return (NULL);
	pt_aux = pt_return;
	while (len--)
		*pt_aux++ = *src++;
	return (pt_return);
}

void	free_memory(char **s)
{
	char	**pt_aux;

	pt_aux = s;
	while (*pt_aux)
	{
		free(*pt_aux);
		pt_aux++;
	}
	free(s);
}
