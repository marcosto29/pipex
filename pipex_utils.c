/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/22 10:24:29 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_parse(int argc, char **argv)
{
	int	fd;
	
	if (argc <= 4)
	{
		ft_printf("Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	fd = open(*(argv + 1), O_RDONLY);
	if (fd < 0)
	{
		perror(*(argv + 1));
		exit(EXIT_FAILURE);
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
