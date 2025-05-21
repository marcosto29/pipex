/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/21 21:39:40 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//search the command on the PATH and writes it on a file
static void	search_command(char *command, int pipe[])
{
	char	**arg_vec;
	char	**env_vec;
	int		save_stdout;

	close(pipe[0]);
	arg_vec = ft_calloc(sizeof(char *), 3);
	arg_vec[0] = ft_strdup("which");
	arg_vec[1] = ft_strdup(command);
	env_vec = ft_calloc(sizeof(char **), 1);
	save_stdout = dup(1);
	dup2(pipe[1], 1);
	if (execve("/usr/bin/which", arg_vec, env_vec) == -1)
	{
		free_memory(arg_vec);
		free_memory(env_vec);
		close(pipe[1]);
		dup2(save_stdout, 1);
		perror("Couldn't find the command");
		exit(EXIT_FAILURE);
	}
}

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*initialize_command(char *command)
{
	char	*cmd;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("Couldn't open pipe");
		return (NULL);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Couldn't fork");
		return (NULL);
	}
	if (pid == 0)
		search_command(command, fd);
	close(fd[1]);
	wait(NULL);
	cmd = get_next_line(fd[0]);
	close(fd[0]);
	if (!cmd)
		return (NULL);
	cmd[ft_strlen(cmd) - 1] = '\0';
	return (cmd);
}

int	main(int argc, char *argv[])
{
	char	**splitted_command;
	char	*cmd;
	char	*env_vec[] = { NULL };
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
	if (execve(cmd, splitted_command, env_vec) == -1)
	{
		perror("Couldn't execute command");
		exit(EXIT_FAILURE);
	}
	//manage output file
	//execute commands
	//execute args
	return (0);
}
