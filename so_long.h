/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:31:43 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/30 13:02:57 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <mlx_int.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <X11/keysym.h>
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# define PLAYER "/mnt/nfs/homes/znaoui/42/so_long/img/player.xpm"
# define WALL "/mnt/nfs/homes/znaoui/42/so_long/img/wall.xpm"
# define COLLECT "/mnt/nfs/homes/znaoui/42/so_long/img/item.xpm"
# define EXIT "/mnt/nfs/homes/znaoui/42/so_long/img/exit.xpm"
# define FLOOR "/mnt/nfs/homes/znaoui/42/so_long/img/floor.xpm"

typedef struct s_map {
	char	**map;
	int		position;
	int		exit;
	int		item;
	int		one;
	int		zero;
	int		x;
	int		y;
	int		mouv;
	int		error;
	int		rect;
}	t_map;

typedef struct s_image {
	void	*img;
	int		height;
	int		width;
}	t_image;

typedef struct s_asset {
	t_image		floor;
	t_image		player;
	t_image		wall;
	t_image		exit;
	t_image		collect;
}	t_asset;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			fd;
	t_image		image;
	t_map		map;
	t_asset		asset;
}	t_vars;

int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_close(int keycode, t_vars *vars);
int		ft_count(char *argv);
int		ft_destroy(t_vars *vars);
int		ft_size_len(unsigned long long nb, int base);
int		ft_putnbr_hexa(unsigned int nb, char c);
int		ft_putnbr_adress(unsigned long long nb, int i);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_init_size(t_vars *vars);
int		ft_check_file(char *argv);
int		ft_found_position(t_vars *vars);
int		ft_find(const char *str);
int		init_img(t_vars *vars);
int		ft_verif_win(t_vars *vars);
size_t	ft_strlen(const char *str);
char	**verif_map(char *argv, t_vars *vars);
char	*ft_strjoin(char *final_str, char *str_lign);
char	*ft_struct_lign(int fd, char *str_final);
char	**ft_struct_array(char *argv, t_vars *vars);
char	*ft_memory_lign(char *str_final);
char	*ft_print_lign(char *str_final);
char	*get_next_line(int fd);
char	*ft_strdup(char *src);
void	ft_free(t_vars *vars);
void	ft_init_map(t_vars *vars);
void	ft_put_img(t_vars *vars);
void	ft_mouv_map(int keycode, t_vars *vars);
void	ft_mouv_left(t_vars *vars);
void	ft_mouv_right(t_vars *vars);
void	ft_mouv_down(t_vars *vars);
void	ft_mouv_up(t_vars *vars);
void	ft_check_exit(const char *str, t_map *t_map);
void	ft_check_position(const char *str, t_map *t_map);
void	ft_check_item(const char *str, t_map *t_map);
void	ft_check_out(const char *str, t_map *t_map);
void	ft_check_rect(const char *str, t_map *t_map, int length);
void	ft_check_char(const char *str, t_map *t_map);
#endif
