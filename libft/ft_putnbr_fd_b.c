/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:04 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 13:58:28 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to print number in any base on specified fd 
void	print_nbr(unsigned long long nbr, const char *b, int b_sz, int fd)
{
	if (nbr / b_sz > 0)
	{
		print_nbr(nbr / b_sz, b, b_sz, fd);
	}
	write(fd, (b + (nbr % b_sz)), 1);
	return ;
}

//function to parse/write a long long in any base on specified fd
void	ft_putnbr_fd_b(long long nbr, const char *b, int b_sz, int fd)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	print_nbr(nbr, b, b_sz, fd);
}
