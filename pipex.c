/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/30 17:25:25 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//search the command on the PATH and writes it on a file
static void	search_command(char *command, int pipe)
{
	char	**arg_vec;
	char	**env_vec;

	arg_vec = ft_calloc(sizeof(char *), 3);
	arg_vec[0] = ft_strdup("which");
	arg_vec[1] = ft_strdup(command);
	env_vec = ft_calloc(sizeof(char **), 1);
	dup2(pipe, 1);
	if (execve("/usr/bin/which", arg_vec, env_vec) == -1)
	{
		perror("Command not found");
		close(pipe);
		exit (1);
	}
}

//check the input command and search for it on PATH
//then writes it on a file redirecting the file descriptor 1 to the one open
static char	*command_parse(char *command)
{
	char	*cmd;
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		search_command(command, fd[1]);
	}
	close(fd[1]);
	wait(NULL);
	cmd = get_next_line(fd[0]);
	close(fd[0]);
	if (!cmd || !*cmd)
		return (NULL);
	cmd[ft_strlen(cmd) - 1] = '\0';
	return (cmd);
}

void	command(char	**argv, int fdi, int fdo)
{
	char	**splitted_command;
	char	**env_vec;
	char	*cmd;
	pid_t	pid;

	if (fdi == -1)
		return ;
	env_vec = ft_calloc(sizeof(char *), 1);
	splitted_command = ft_split_pipex(*argv, ' ');
	cmd = command_parse(*splitted_command);
	if (!cmd)
		cmd = *splitted_command;
	pid = fork();
	if (pid == 0)
	{
		dup2(fdo, 1);
		dup2(fdi, 0);
		if (execve(cmd, splitted_command, env_vec) == -1)
		{
			perror(cmd);
			exit (1);
		}
	}
	wait(NULL);
}

int	main(int argc, char *argv[])
{
	int		fdi;
	int		fdo;
	int		pipe_fd[2];
	int		tmp_pipe;

	if (argc < 4)
		exit(1);
	argv++;
	fdi = open(*argv, O_RDONLY);
	if (fdi == -1)
		perror(*argv);
	argv++;
	while (argc-- > 4)
	{
		pipe(pipe_fd);
		command(argv++, fdi, pipe_fd[1]);
		close(tmp_pipe);
		tmp_pipe = pipe_fd[0];
		close(pipe_fd[1]);
		fdi = pipe_fd[0];
	}
	fdo = open(*(argv + 1), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	command(argv, fdi, fdo);
	return (close(fdo), close(fdi), 0);
}
