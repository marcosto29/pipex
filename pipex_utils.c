/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/20 20:50:11 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_memory(char **s)
{
	char	**pt_aux;

	pt_aux = s;
	while(*pt_aux)
	{
		free(*pt_aux);
		pt_aux++;
	}
	free(s);
}