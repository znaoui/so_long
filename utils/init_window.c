/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:19:11 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 12:51:57 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_destroy(t_vars *vars)
{
	if (vars->asset.player.img)
		mlx_destroy_image(vars->mlx, vars->asset.player.img);
	if (vars->asset.floor.img)
		mlx_destroy_image(vars->mlx, vars->asset.floor.img);
	if (vars->asset.wall.img)
		mlx_destroy_image(vars->mlx, vars->asset.wall.img);
	if (vars->asset.collect.img)
		mlx_destroy_image(vars->mlx, vars->asset.collect.img);
	if (vars->asset.exit.img)
		mlx_destroy_image(vars->mlx, vars->asset.exit.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	ft_free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	init_img(t_vars *vars)
{
	vars->asset.player.img = mlx_xpm_file_to_image(vars->mlx, PLAYER,
			&vars->image.width, &vars->image.height);
	vars->asset.floor.img = mlx_xpm_file_to_image(vars->mlx, FLOOR,
			&vars->image.width, &vars->image.height);
	vars->asset.wall.img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->image.width, &vars->image.height);
	vars->asset.collect.img = mlx_xpm_file_to_image(vars->mlx, COLLECT,
			&vars->image.width, &vars->image.height);
	vars->asset.exit.img = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->image.width, &vars->image.height);
	if (vars->asset.player.img == NULL || vars->asset.floor.img == NULL
		|| vars->asset.wall.img == NULL
		|| vars->asset.collect.img == NULL || vars->asset.exit.img == NULL)
		return (0);
	else
		return (1);
}

void	ft_put_img2(t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->asset.player.img, y * 32, x * 32);
	else if (vars->map.map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->asset.floor.img, y * 32, x * 32);
	else if (vars->map.map[x][y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->asset.wall.img, y * 32, x * 32);
	else if (vars->map.map[x][y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->asset.collect.img, y * 32, x * 32);
	else if (vars->map.map[x][y] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->asset.exit.img, y * 32, x * 32);
}

void	ft_put_img(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map.map[x] != NULL)
	{
		y = 0;
		while (vars->map.map[x][y] != '\0')
		{
			ft_put_img2(vars, x, y);
			y++;
		}
		x++;
	}
}

int	ft_init_size(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[i])
		i++;
	return (i);
}
