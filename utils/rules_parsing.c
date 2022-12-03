/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:24:32 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/11 10:37:29 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_exit(const char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E')
			map->exit += 1;
		i++;
	}
}

void	ft_check_position(const char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
		{
			map->position += 1;
		}
		i++;
	}
}

void	ft_check_item(const char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			map->item += 1;
		i++;
	}
}

void	ft_check_out(const char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == '1')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
			i++;
	if (str[i] != '\0')
	{
		map->error = 1;
		ft_printf("Error\nLa map n'est pas entourer de mur.\n");
	}
}
