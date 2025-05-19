/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:36:34 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:43:59 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	number_size(long long aux_n)
{
	unsigned int	size;

	size = 1;
	while (aux_n / 10 > 0)
	{
		aux_n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_recursive(char *string, long long n)
{
	if (n / 10 > 0)
		string = ft_recursive(string, n / 10);
	*string++ = n % 10 + '0';
	return (string);
}

//function to transform an integer to a string
char	*ft_itoa(long long n)
{
	char			*pt_return;
	unsigned int	size;
	unsigned int	negative;

	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative++;
	}
	size = number_size(n);
	pt_return = ft_calloc(sizeof(char), size + 1 + negative);
	if (!pt_return)
		return (NULL);
	if (negative > 0)
		*pt_return = '-';
	ft_recursive(pt_return + negative, n);
	return (pt_return);
}
