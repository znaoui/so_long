/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:54 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/09 15:29:54 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_type(va_list args, char c)
{
	int	size_len;

	size_len = 0;
	if (c == 's')
		size_len += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		size_len += ft_putchar((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		size_len += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		size_len += ft_putnbr_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
		size_len += ft_putnbr_adress(va_arg(args, unsigned long long), 0);
	else if (c == 'u')
		size_len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		size_len += ft_putchar('%');
	else
		return (-1);
	return (size_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			char_count += ft_type(args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			char_count++;
		}
		i++;
	}
	va_end(args);
	return (char_count);
}
