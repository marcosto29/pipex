/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/22 13:08:40 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*last_string(char **ds)
{
	while (*(ds + 1))
		ds++;
	return (*ds);
}
size_t	ft_strlen_double(char **ds)
{
	size_t size;

	size = 0;
	while (*ds)
	{
		size++;
		ds++;
	}
	return (size);
}

char	**add_string(char **ds, char *s)
{
	char	**pt_return;
	char	**pt_aux;
	char	**pt_aux2;
	int		size;

	size = ft_strlen_double(ds);
	pt_return = ft_calloc(sizeof(char *), size + 2);
	if (!pt_return)
		return (NULL);
	pt_aux = pt_return;
	pt_aux2 = ds;
	while (*pt_aux2)
	{
		*pt_aux = ft_strdup(*pt_aux2);
		pt_aux++;
		pt_aux2++;
	}
	*pt_aux = ft_strdup(s);
	free_memory(ds);
	return (pt_return);
}

void	input_parse(int argc, char **argv)
{
	int	fd;
	
	// if (argc <= 4)
	// {
	// 	ft_printf("Not enough arguments\n");
	// 	exit(1);
	// }
	fd = open(*argv, O_RDONLY);
	if (fd < 0)
	{
		perror(*argv);
		exit(1);
	}
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
