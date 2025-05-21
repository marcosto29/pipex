/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/21 16:41:12 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//search the command on the PATH and writes it on a file
static void	search_command(char *command)
{
	char	**arg_vec;
	char	**env_vec;
	int		fd;

	arg_vec = ft_calloc(sizeof(char *), 3);
	arg_vec[0] = ft_strdup("which");
	arg_vec[1] = ft_strdup(command);
	env_vec = ft_calloc(sizeof(char **), 1);
	fd = open("Path", O_CREAT | O_WRONLY);
	if (fd < 0)
	{
		perror("Couldn't open the file to write");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	close(fd);
	if (execve("/usr/bin/which", arg_vec, env_vec) == -1)
	{
		perror("Couldn't find the command");
		exit(EXIT_FAILURE);
	}
}

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*initialize_command(char *command)
{
	char	*cmd;
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Couldn't fork");
		return (NULL);
	}
	if (pid == 0)
		search_command(command);
	wait(NULL);
	fd = open("Path", O_RDONLY);
	if (fd < 0)
	{
		perror("Couldn't open the file to read");
		return (NULL);
	}
	cmd = get_next_line(fd);
	close(fd);
	if (!cmd)
		return (NULL);
	cmd[ft_strlen(cmd) - 1] = '\0';
	return (cmd);
}

int	main(int argc, char *argv[])
{
	char	**splitted_command;
	char	*cmd;
	char	**arg_vec;
	char	*env_vec[] = { "PWD=/home/matoledo/Desktop", NULL };
	char	*input_file;

	argv++;
	//input_file = ft_strdup(*argv);
	splitted_command = ft_split(*argv, ' ');
	cmd = initialize_command(*splitted_command);
	if (!cmd)
	{
		perror("Command error");
		exit(EXIT_FAILURE);
	}
	arg_vec = ft_strdup_double(splitted_command);
	// env_vec = ft_calloc(sizeof(char *), 2);
	// *env_vec = ft_strdup("PATH=/home/matoledo/Desktop");
	if (execve(cmd, arg_vec, env_vec) == -1)
	{
		perror("Couldn't execute command");
		exit(EXIT_FAILURE);
	}
	//manage output file
	//execute commands
	//execute args
	return (0);
}
