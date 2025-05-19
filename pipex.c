/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 23:27:51 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	char	**argVec;
	char	**envVec = {NULL};
	char	*cmd;
	char	**full_command;
	int		size;

	ft_printf("|==================================| %d\n", argc);
	argv++;
	//manage input file
	argv++;
	full_command = ft_split(*argv, ' ');
	cmd = ft_strdup("/usr/bin/");
	cmd = ft_strjoin(cmd, *full_command);
	full_command++;
	argVec = ft_strdup_double(full_command);
	if (command_parse(argVec) == -1)
		perror("todo mal");
	if (execve(cmd, argVec, envVec) == -1)
		perror("Comando mal");
	return (0);
}
