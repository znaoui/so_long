/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:23:39 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/10 16:15:35 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_here(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			return (i);
		i++;
	}
	return (0);
}

int	ft_found_position(t_vars *vars)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (vars->map.map[i])
	{
		if (ft_is_here(vars->map.map[i]) >= 1)
		{
			vars->map.x = i;
			vars->map.y = ft_is_here(vars->map.map[i]);
		}
		i++;
	}
	return (0);
}
