/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:47:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/19 12:49:07 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parse_mem(unsigned long long number, const char *base, int fd)
{
	if (!number)
		return ((int)write(fd, "(nil)", 5));
	write(1, "0x", 2);
	return (print_nbr_r(number, base, (int)ft_strlen(base), 1) + 2);
}

static int	ft_print_selector(char type, va_list args)
{
	if (type == '%')
		return (ft_putchar_fd_r('%', 1));
	else if (type == 'c')
		return (ft_putchar_fd_r((char)va_arg(args, int), 1));
	else if (type == 's')
		return (ft_putstr_fd_r(va_arg(args, char *), 1));
	else if (type == 'p')
		return (ft_parse_mem((unsigned long long)va_arg(args, void *),
				"0123456789abcdef", 1));
	else if (type == 'x')
		return (ft_putnbr_fd_b_r(va_arg(args, unsigned int),
				"0123456789abcdef", (int)ft_strlen("0123456789abcdef"), 1));
	else if (type == 'X')
		return (ft_putnbr_fd_b_r(va_arg(args, unsigned int),
				"0123456789ABCDEF", (int)ft_strlen("0123456789ABCDEF"), 1));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_fd_b_r(va_arg(args, int),
				"0123456789", (int)ft_strlen("0123456789"), 1));
	else if (type == 'u')
		return (ft_putnbr_fd_b_r((unsigned int)va_arg(args, int),
				"0123456789", (int)ft_strlen("0123456789"), 1));
	return (0);
}

int	ft_printf(char const *input_text, ...)
{
	va_list	args;
	int		size_return;

	if (!input_text)
		return (-1);
	size_return = 0;
	va_start(args, input_text);
	while (*input_text)
	{
		if (*input_text == '%')
		{
			input_text++;
			while (*input_text == 32 && *input_text)
				input_text++;
			if (!*input_text)
				return (-1);
			size_return += ft_print_selector(*input_text, args);
			input_text ++;
		}
		else
			size_return += (int)write(1, input_text++, 1);
	}
	va_end(args);
	return (size_return);
}
