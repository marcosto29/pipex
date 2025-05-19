/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:37:47 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:32:34 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to create a new string from applying the external function f
//to every character of the string s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*pt_return;
	char			*pt_aux;
	unsigned int	index;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	pt_return = ft_calloc(sizeof(char), (s_len + 1));
	if (!pt_return)
		return (NULL);
	pt_aux = pt_return;
	index = 0;
	while (*s)
	{
		*pt_aux++ = f(index, *s++);
		index++;
	}
	return (pt_return);
}
