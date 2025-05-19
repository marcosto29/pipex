/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:11:14 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:27:52 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to create a new string with the content of the string s
char	*ft_strdup(const char *s)
{
	size_t	allocate_memory;
	char	*pt_return;

	allocate_memory = ft_strlen(s);
	pt_return = ft_calloc(sizeof(char), allocate_memory + 1);
	if (!pt_return)
		return (NULL);
	ft_memcpy(pt_return, s, allocate_memory);
	return (pt_return);
}
