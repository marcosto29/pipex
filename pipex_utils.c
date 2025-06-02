/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/02 10:48:26 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_errors(int fdi, int fdo, char *argvi, char *argvo)
{
	if (fdi == -1)
		perror(argvi);
	if (fdo == -1)
	{
		perror(argvo);
		exit (1);
	}
}

char	*last_string(char **ds)
{
	while (*(ds + 1))
		ds++;
	return (*ds);
}

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
		free(*pt_aux++);
	free(splitted_word);
}

//read from the input and write it on the pipe thats gonna be input for execve
int	here_doc_parse(char **argv)
{
	int		pipe_fd[2];
	char	*line;

	pipe(pipe_fd);
	line = get_next_line(0);
	while (!ft_strnstr(line, *argv, ft_strlen(line)))
	{
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
