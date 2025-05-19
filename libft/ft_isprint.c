/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:50:45 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 10:56:07 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function to check if a character is printable
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	return (0);
}
