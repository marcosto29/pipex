/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_b_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:04 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 14:00:44 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to print number in any base and return the bytes wrritten
// on specified fd 
int	print_nbr_r(unsigned long long nbr, const char *b, int b_sz, int fd)
{
	int	bytes_returned;

	bytes_returned = 0;
	if (nbr / b_sz > 0)
	{
		bytes_returned += print_nbr_r(nbr / b_sz, b, b_sz, fd);
	}
	return (bytes_returned + (int)write(fd, (b + (nbr % b_sz)), 1));
}

//function to parse/write a long long number in any base
// and return the bytes written on specified fd
int	ft_putnbr_fd_b_r(long long nbr, const char *b, int b_sz, int fd)
{
	int	bytes_returned;

	bytes_returned = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		bytes_returned += (int)write(fd, "-", 1);
	}
	bytes_returned += print_nbr_r(nbr, b, b_sz, fd);
	return (bytes_returned);
}
