/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:42:45 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:25:02 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to write an integer on specified fd and return the bytes written
int	ft_putnbr_fd_r(int n, int fd)
{
	char	c;
	int		bytes_returned;

	bytes_returned = 0;
	if (n == -2147483648)
	{
		return ((int)write(fd, "-2147483648", 11));
	}
	if (n < 0)
	{
		n *= -1;
		bytes_returned += write(fd, "-", 1);
	}
	if (n / 10 > 0)
		bytes_returned += ft_putnbr_fd_r(n / 10, fd);
	c = n % 10 + '0';
	return (bytes_returned + (int)write(fd, &c, 1));
}
