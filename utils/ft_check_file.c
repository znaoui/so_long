/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 08:19:40 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 12:25:04 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[i] != NULL)
	{
		free(vars->map.map[i]);
		i++;
	}
	free(vars->map.map);
}

int	ft_check_file(char *argv)
{
	char	*ext;
	int		i;
	int		y;

	i = 0;
	y = 0;
	ext = ".ber";
	if (ft_strlen(argv) <= 4)
		return (-1);
	while (argv[i] != '\0')
	{
		if (argv[i] == ext[y])
		{
			if (argv[i -1] == '/')
				return (-1);
			while (argv[i] != '\0' && ext[y] != '\0' && ext[y++] == argv[i])
				i++;
			if (argv[i] == '\0' && ext[y] == '\0')
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	ft_verif_win(t_vars *vars)
{
	int	x;
	int	y;

	x = ft_strlen(vars->map.map[0]);
	y = ft_init_size(vars);
	if (vars->map.map[0] == NULL)
	{
		ft_printf("La map est vide\n");
		return (1);
	}
	if (x * 32 > 2560)
	{
		ft_printf("La map est trop grande.\n");
		return (1);
	}
	else if (y * 32 > 1440)
	{
		ft_printf("La map est trop grande.\n");
		return (1);
	}
	else
		return (0);
}
