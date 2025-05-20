/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/20 20:06:01 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*initialize_command(char *command)
{
	char	*cmd;
	char	**argVec;
	char	**envVec;
	int		fd;

	pid_t pid = fork();
	if (pid == 0)
	{
		argVec = ft_calloc(sizeof(char**), 3);
		argVec[0] = ft_strdup("which");
		argVec[1] = ft_strdup(command);
		envVec = ft_calloc(sizeof(char**), 1);
		fd = open("Path", O_WRONLY | O_CREAT);
		dup2(fd, 1);
		if (execve("/usr/bin/which", argVec, envVec) == -1)
			perror("Command not found");
	}
	wait(NULL);
	fd = open("Path", O_RDONLY);
	cmd = get_next_line(fd);
	cmd[ft_strlen(cmd) - 1] = '\0';
	close(fd);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char	**splitted_command;
	// char	**argVec;
	// char	**envVec = {NULL};
	char	*cmd;
	
	argv++;
	splitted_command = ft_split(*argv, ' ');
	//manage commands
	cmd = initialize_command(*splitted_command);
	//manage args
	// if (!argVec)
	// {
	// 	perror("Bad arguments");
	// 	return (1);
	// }
	//manage output file
	//execute commands
	//execute args
	return (0);
}
