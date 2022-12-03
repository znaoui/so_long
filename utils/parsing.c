/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:20:17 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 12:35:46 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count(char *argv)
{
	char		*str_cpy;
	int			len;
	int			fp;

	len = 0;
	fp = open(argv, O_RDONLY);
	if (fp < 0)
		return (0);
	str_cpy = get_next_line(fp);
	if (!str_cpy)
		return (0);
	while (str_cpy != NULL)
	{
		free(str_cpy);
		str_cpy = get_next_line(fp);
		len++;
	}
	free(str_cpy);
	close (fp);
	return (len);
}

char	**ft_struct_array(char *argv, t_vars *vars)
{
	char			*str_cpy;
	int				i;
	int				len;

	ft_init_map(vars);
	i = 0;
	len = ft_count(argv);
	if (vars->fd < 0 || len <= 0)
		return (NULL);
	str_cpy = get_next_line(vars->fd);
	vars->map.map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!vars->map.map)
		return (NULL);
	while (str_cpy != NULL)
	{
		vars->map.map[i] = str_cpy;
		i++;
		str_cpy = get_next_line(vars->fd);
	}
	vars->map.map[i] = NULL;
	free(str_cpy);
	close(vars->fd);
	return (vars->map.map);
}

void	ft_check_error(t_vars *vars)
{
	if (vars->map.item < 1)
	{
		vars->map.error = 1;
		ft_printf("Error\nLa map ne contient pas d'item.\n");
	}
	if (vars->map.position != 1)
	{
		vars->map.error = 1;
		ft_printf("Error\nLa map doit contenir UNE position de depart.\n");
	}
	if (vars->map.exit < 1)
	{
		vars->map.error = 1;
		ft_printf("Error\nLa map ne contient aucune sortie\n");
	}
	if (vars->map.rect == 1)
	{
		vars->map.error = 1;
		ft_printf("Error\nLa map n'est pas rectangulaire\n");
	}
	if (vars->map.error == 1)
		ft_destroy(vars);
}

char	**verif_map(char *argv, t_vars *vars)
{
	int		i;
	int		len;

	ft_struct_array(argv, vars);
	i = 0;
	len = ft_count(argv);
	if (!vars->map.map || len <= 0)
		ft_destroy(vars);
	while (vars->map.map[i] != NULL)
	{	
		if (i == 0 || i == (len - 1))
			ft_check_out(vars->map.map[i], &vars->map);
		ft_check_char(vars->map.map[i], &vars->map);
		ft_check_exit(vars->map.map[i], &vars->map);
		ft_check_position(vars->map.map[i], &vars->map);
		ft_check_item(vars->map.map[i], &vars->map);
		ft_check_rect(vars->map.map[i], &vars->map,
			ft_strlen(vars->map.map[0]));
		i++;
	}
	ft_check_error(vars);
	return (vars->map.map);
}
