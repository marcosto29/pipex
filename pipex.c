/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 17:50:45 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/libftprintf.h"

int	main(int argc, char **argv)
{
	ft_printf("%d\n", argc);
	argv++;
	while (*argv)
	{
		ft_printf("%s\n", *argv);
		argv++;
	}
	return (0);
}
