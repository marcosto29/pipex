/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:43:13 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/01 13:06:54 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_parse(char **argv)
{
	int		pipe_fd[2];
	char	*line;

	pipe(pipe_fd);
	line = get_next_line(0);
	line[ft_strlen(line) - 1] = '\0';
	write(pipe_fd[1], line, ft_strlen(line));
	while(!ft_strnstr(line, *argv, ft_strlen(line)))
	{
		line = get_next_line(0);
		write(pipe_fd[1], line, ft_strlen(line));
		line[ft_strlen(line) - 1] = '\0';
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
