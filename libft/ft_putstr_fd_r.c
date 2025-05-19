/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:57:24 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 14:09:32 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to write the string s on specified fd and return th bytes written
int	ft_putstr_fd_r(char *s, int fd)
{
	int	bytes_printed;

	if (!s)
		return ((int)write(fd, "(null)", 6));
	bytes_printed = 0;
	while (*s)
		bytes_printed += (int)write(fd, s++, 1);
	return (bytes_printed);
}
