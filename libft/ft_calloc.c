/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:12 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:13:18 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to allocate memory and fill it  with null
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*pt_call;

	total = nmemb * size;
	pt_call = malloc(total);
	if (!pt_call)
		return (NULL);
	ft_bzero(pt_call, total);
	return (pt_call);
}
