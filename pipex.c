/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/20 21:35:19 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//search the command on the PATH and writes it on a file
void	search_command(int fd, char *command)
{
	char	**argVec;
	char	**envVec;
	int		save_stdout;

	argVec = ft_calloc(sizeof(char*), 3);
	argVec[0] = ft_strdup("which");
	argVec[1] = ft_strdup(command);
	envVec = ft_calloc(sizeof(char*), 1);
	save_stdout = dup(1);
	dup2(fd, 1);
	close(fd);
	if (execve("/usr/bin/which", argVec, envVec) == -1)
	{
		free_memory(argVec);
		free_memory(envVec);
		perror("Command not found");
		dup2(save_stdout, 1);
		close(save_stdout);
		exit(EXIT_FAILURE);
	}
}

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*initialize_command(char *command)
{
	char	*cmd;
	int		fd;

	pid_t pid = fork();
	if (pid == 0)
	{
		fd = open("Path", O_WRONLY | O_CREAT);
		if (fd < 0)
		{
			perror("error abriendo el archivo");
			exit(EXIT_FAILURE);
		}
		search_command(fd, command);
	}
	wait(NULL);
	fd = open("Path", O_RDONLY);
	cmd = get_next_line(fd);
	cmd[ft_strlen(cmd) - 1] = '\0';
	close(fd);
	return (cmd);
}

int	main(int argc, char *argv[])
{
	char	**splitted_command;
	char	*cmd;
	
	argv++;
	//manage input file
	splitted_command = ft_split(*argv, ' ');
	cmd = initialize_command(*splitted_command);
	//manage args
	//manage output file
	//execute commands
	//execute args
	return (0);
}