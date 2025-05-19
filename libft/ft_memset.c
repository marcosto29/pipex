/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:12:54 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:21:26 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to set all data of dest to c
void	*ft_memset(void *dest, int c, size_t n)
{
	char	*pt_dest;

	pt_dest = dest;
	while (n--)
	{
		*pt_dest++ = (char)c;
	}
	return (dest);
}
