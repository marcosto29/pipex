/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:44:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:19:49 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to get and return the first instance of c inside s
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*pt_char;

	pt_char = s;
	while (n--)
	{
		if (*pt_char == (char) c)
		{
			return ((char *)pt_char);
		}
		pt_char++;
	}
	return (NULL);
}
