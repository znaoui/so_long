/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:24:32 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 12:18:40 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_vars *vars)
{
	vars->asset.collect.img = NULL;
	vars->asset.exit.img = NULL;
	vars->asset.wall.img = NULL;
	vars->asset.player.img = NULL;
	vars->asset.floor.img = NULL;
	vars->map.map = NULL;
	vars->win = NULL;
	vars->mlx = NULL;
	vars->map.error = 0;
	vars->map.exit = 0;
	vars->map.y = 0;
	vars->map.x = 0;
	vars->map.position = 0;
	vars->map.item = 0;
	vars->map.one = 0;
	vars->map.zero = 0;
	vars->map.mouv = 0;
	vars->map.rect = 0;
}

void	ft_check_rect(const char *str, t_map *map, int length)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (len != length || str[i] != '1')
	{
		map->rect = 1;
		map->error = 1;
	}
	while (str[i] != '\0')
		i++;
	if (str[i - 2] != '1')
	{	
		map->rect = 1;
		map->error = 1;
	}
}

void	ft_check_char(const char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E' || str[i] == 'C' || str[i] == 'P' || str[i] == '0'
			|| str[i] == '1' || str[i] == '\n')
			i++;
		else
		{
			ft_printf("Error\nLa map contient un caractere invalide.\n");
			map->error = 1;
			i++;
		}
	}
}
