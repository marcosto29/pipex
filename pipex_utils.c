/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/01 10:26:26 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_empty(char *s)
{
	while (*s)
	{
		if (*s)
			return (0);
		s++;
	}
	return (1);
}

void	free_memory(char **splitted_word)
{
	char	**pt_aux;

	pt_aux = splitted_word;
	while (*pt_aux)
	{
		printf("hola: %s\n", *pt_aux);
		free(*pt_aux++);
	}
	free(splitted_word);
}
