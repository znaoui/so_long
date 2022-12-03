/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:23:39 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 12:22:25 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mouv_left(t_vars *vars)
{
	int	i;
	int	x;

	i = vars->map.x;
	x = vars->map.y;
	if (vars->map.map[i][x] == 'P')
	{
		if (vars->map.map[i][x -1] != '1' && vars->map.map[i][x -1] != 'E')
		{
			if (vars->map.map[i][x -1] == 'C')
				vars->map.item -= 1;
			vars->map.map[i][x -1] = 'P';
			vars->map.map[i][x] = '0';
			ft_printf("%d\n", vars->map.mouv += 1);
			ft_put_img(vars);
		}
		else if (vars->map.map[i][x -1] == 'E')
		{
			if (vars->map.item == 0)
			{
				ft_printf("%d\n", vars->map.mouv += 1);
				ft_destroy(vars);
			}
		}
	}
}

void	ft_mouv_right(t_vars *vars)
{
	int	i;
	int	x;

	i = vars->map.x;
	x = vars->map.y;
	if (vars->map.map[i][x] == 'P')
	{
		if (vars->map.map[i][x +1] != '1' && vars->map.map[i][x +1] != 'E')
		{
			if (vars->map.map[i][x +1] == 'C')
				vars->map.item -= 1;
			vars->map.map[i][x +1] = 'P';
			vars->map.map[i][x] = '0';
			ft_printf("%d\n", vars->map.mouv += 1);
			ft_put_img(vars);
		}
		else if (vars->map.map[i][x +1] == 'E')
		{
			if (vars->map.item == 0)
			{
				ft_printf("%d\n", vars->map.mouv += 1);
				ft_destroy(vars);
			}
		}
	}
}

void	ft_mouv_down(t_vars *vars)
{
	int	i;
	int	x;

	i = vars->map.x;
	x = vars->map.y;
	if (vars->map.map[i][x] == 'P')
	{
		if (vars->map.map[i +1][x] != '1' && vars->map.map[i +1][x] != 'E')
		{
			if (vars->map.map[i +1][x] == 'C')
				vars->map.item -= 1;
			vars->map.map[i +1][x] = 'P';
			vars->map.map[i][x] = '0';
			ft_printf("%d\n", vars->map.mouv += 1);
			ft_put_img(vars);
		}
		else if (vars->map.map[i +1][x] == 'E')
		{
			if (vars->map.item == 0)
			{
				ft_printf("%d\n", vars->map.mouv += 1);
				ft_destroy(vars);
			}
		}
	}
}

void	ft_mouv_up(t_vars *vars)
{
	int	i;
	int	x;

	i = vars->map.x;
	x = vars->map.y;
	if (vars->map.map[i][x] == 'P')
	{
		if (vars->map.map[i -1][x] != '1' && vars->map.map[i -1][x] != 'E')
		{
			if (vars->map.map[i -1][x] == 'C')
				vars->map.item -= 1;
			vars->map.map[i -1][x] = 'P';
			vars->map.map[i][x] = '0';
			ft_printf("%d\n", vars->map.mouv += 1);
			ft_put_img(vars);
		}
		else if (vars->map.map[i -1][x] == 'E')
		{
			if (vars->map.item == 0)
			{
				ft_printf("%d\n", vars->map.mouv += 1);
				ft_destroy(vars);
			}
		}
	}
}
