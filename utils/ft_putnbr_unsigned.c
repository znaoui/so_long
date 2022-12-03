/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:43:13 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/09 15:30:58 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	nbr;
	int				len;

	nbr = nb;
	len = 0;
	if (nbr > 9)
	{
		len += ft_putnbr_unsigned(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (ft_size_len(nb, 10));
}
