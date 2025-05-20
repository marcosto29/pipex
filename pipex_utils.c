/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:33:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/20 13:07:27 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_strcpy_double(char **dest, const char **src, size_t n)
{
	char		**pt_dest;
	const char	**pt_src;

	pt_src = src;
	pt_dest = dest;
	if (!src && !dest)
		return (dest);
	while (n--)
	{
		*pt_dest++ = (char *)*pt_src++;
	}
	return (dest);
}

char	**str_join_double(const char **s1, const char **s2)
{
	char	**pt_return;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen_double(s1);
	len2 = ft_strlen_double(s2);
	pt_return = ft_calloc(sizeof(char**), len1 + len2 + 1);
	if (!pt_return)
		return (NULL);
	ft_strcpy_double(pt_return, s1, len1);
	ft_strcpy_double(pt_return + len1, s2, len2);
	return (pt_return);
}

size_t ft_strlen_double(const char **s)
{
	size_t	size;

	size = 0;
	while(*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	**ft_strdup_double(const char **s)
{
	char	**pt_return;
	size_t	len;

	len = ft_strlen_double(s);
	pt_return = ft_calloc(sizeof(char **), len + 1);
	if (!pt_return)
		return (NULL);
	ft_strcpy_double(pt_return, s, len);
	return(pt_return);
}
