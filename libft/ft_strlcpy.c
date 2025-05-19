/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:00:41 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:30:52 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to check if able and try to copy the string src into dest
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;
	char	*pt_dest;

	counter = ft_strlen(src);
	if (size == 0)
		return (counter);
	pt_dest = dest;
	while (size-- > 1 && *src)
		*pt_dest++ = *src++;
	*pt_dest = '\0';
	return (counter);
}
