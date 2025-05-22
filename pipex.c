/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/22 14:40:07 by matoledo         ###   ########.fr       */
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
		perror("Error finding the command");
		exit(1);
	}
}

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*command_parse(char *command)
{
	char	*cmd;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(1);
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
	int		fdi;
	int		fdo;

	argv++;
	input_parse(argc, argv);
	fdi = open(*argv, O_RDONLY);
	dup2(fdi, 0);
	argv++;
	splitted_command = ft_split(*argv, ' ');
	cmd = command_parse(*splitted_command);
	if (!cmd || !*cmd)
	{
		perror("Error finding the command");
		exit(1);
	}
	fdo = open(last_string(argv), O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	dup2(fdo, 1);
	if (execve(cmd, splitted_command, env_vec) == -1)
	{
		perror("Error executing the command");
		exit(1);
	}
	return (0);
}
