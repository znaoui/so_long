/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:19:11 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 13:05:13 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_mouv(int keycode, t_vars *vars)
{
	ft_found_position(vars);
	if (keycode == 119)
		ft_mouv_up(vars);
	if (keycode == 97)
		ft_mouv_left(vars);
	if (keycode == 115)
		ft_mouv_down(vars);
	if (keycode == 100)
		ft_mouv_right(vars);
	if (keycode == 65307)
		ft_destroy(vars);
	return (0);
}

void	ft_check_init(t_vars *vars)
{
	if (!init_img(vars))
	{
		ft_printf("Une erreur de texture est presente\n");
		ft_destroy(vars);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2 && ft_check_file(argv[1]) == 0)
	{
		vars.fd = open(argv[1], O_RDONLY);
		if (vars.fd < 0 || read(vars.fd, 0, 0) == -1)
			return (1);
		verif_map(argv[1], &vars);
		if (ft_verif_win(&vars) == 1)
			return (ft_destroy(&vars));
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			return (ft_destroy(&vars));
		vars.win = mlx_new_window(vars.mlx, ft_strlen(vars.map.map[0])
				* 32 - 32, ft_init_size(&vars) * 32, "so_long");
		if (vars.win == NULL)
			return (ft_destroy(&vars));
		ft_check_init(&vars);
		ft_put_img(&vars);
		mlx_hook(vars.win, 2, 1L << 0, ft_mouv, &vars);
		mlx_hook(vars.win, 17, 1L << 17, ft_destroy, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
