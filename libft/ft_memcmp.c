/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:31:47 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:32:12 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to compare s1 and s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*pt_s1;
	const char	*pt_s2;

	pt_s1 = s1;
	pt_s2 = s2;
	while (n--)
	{
		if (*pt_s1 != *pt_s2)
		{
			return (*(unsigned char *)pt_s1 - *(unsigned char *)pt_s2);
		}
		pt_s1++;
		pt_s2++;
	}
	return (0);
}
