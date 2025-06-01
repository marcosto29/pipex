/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:43:13 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/01 11:03:08 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_parse(char **argv)
{
	int		pipe_fd[2];
	char	*line;
	int		fd;

	fd = open("hola", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	pipe(pipe_fd);
	dup2(fd, 1);
	line = get_next_line(0);
	line[ft_strlen(line) - 1] = '\0';
	while(ft_strncmp(line, *argv, ft_strlen(line)) != 0)
	{
		ft_printf("%s\n", line);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
	}
}