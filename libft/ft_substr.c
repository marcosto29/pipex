/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:18:54 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:36:23 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to create a substring of s from the start point with length len
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pt_return;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	pt_return = ft_calloc(sizeof(char), len + 1);
	if (!pt_return)
		return (NULL);
	ft_memcpy(pt_return, s + start, len);
	return (pt_return);
}
