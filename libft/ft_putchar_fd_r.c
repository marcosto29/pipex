/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:06:07 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:23:42 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to wirte the char c on specified fd and return the bytes written
int	ft_putchar_fd_r(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}
