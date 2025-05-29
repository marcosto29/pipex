/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/29 18:56:05 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//search the command on the PATH and writes it on a file
static void	search_command(char *command, int pipe)
{
	char	**arg_vec;
	char	**env_vec;
	int		save_stdout;

	arg_vec = ft_calloc(sizeof(char *), 3);
	arg_vec[0] = ft_strdup("which");
	arg_vec[1] = ft_strdup(command);
	env_vec = ft_calloc(sizeof(char **), 1);
	save_stdout = dup(1);
	dup2(pipe, 1);
	if (execve("/usr/bin/which", arg_vec, env_vec) == -1)
	{
		free_memory(arg_vec);
		free_memory(env_vec);
		close(pipe);
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
	{
		perror("Command not found");
		exit(1);
	}
	cmd[ft_strlen(cmd) - 1] = '\0';
	return (cmd);
}

void	command(char	**argv, int fdi, int fdo)
{
	char	**splitted_command;
	char	**env_vec;
	char	*cmd;
	pid_t	pid;

	env_vec = ft_calloc(sizeof(char *), 1);
	splitted_command = ft_split(*argv, ' ');
	cmd = command_parse(*splitted_command);
	pid = fork();
	if (pid == 0)
	{
		dup2(fdo, 1);
		dup2(fdi, 0);
		if (execve(cmd, splitted_command, env_vec) == -1)
		{
			perror("Error executing the command");
			exit(1);
		}
	}
	wait(NULL);
}

//TODO: gestión de errores
//TODO: arreglar la fokin norminette
int	main(int argc, char *argv[])
{
	int		fdi;
	int		fdo;
	int		pipe_fd[2];
	int		tmp_pipe;

	argv++;
	input_parse(argc, argv);
	fdi = open(*argv, O_RDONLY);
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
	close(fdo);
	close(fdi);
	return (0);
}
