/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:08:22 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/09 15:30:44 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr_adress(unsigned long long nb, int i)
{
	unsigned long long	nbr;
	char				*hexa;

	hexa = "0123456789abcdef";
	nbr = nb;
	if (i == 0)
		i = write(1, "0x", 2);
	if (nbr > 15)
	{
		ft_putnbr_adress((nbr / 16), i);
		ft_putchar(hexa[nbr % 16]);
	}
	else
		ft_putchar(hexa[nbr % 16]);
	return (ft_size_len(nb, 16) + 2);
}
