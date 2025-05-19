/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:04:44 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:31:08 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to get the length of a string
size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (*c++)
	{
		counter++;
	}
	return (counter);
}
