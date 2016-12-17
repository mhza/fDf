/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:50:09 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/16 16:15:34 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# define BUFF_SIZE 1500
# define WIN_X 2000
# define WIN_Y 1400
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef	struct	s_line
{
	float	cp1;
	float	cp2;
	int		dx;
	int		dy;
	int		x;
	int		y;
}				t_line;

typedef	struct	s_point
{
	int	x0;
	int	y0;
	int	x;
	int	y;
	int	z;
}				t_point;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	char	*map;
	float	c1;
	float	c2;
	float	divpi;
	int		is_iso;
	int		ln;
	int		col;
	float	piv;
	int		zoom;
	int		manz;
	int		tr;
	int		td;
	int		is_decr;
	int		zmax;
	int		zmin;
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;
	t_point	*points;
}				t_env;

void			ft_draw(void *mlx, void *win, int x, int y);
int				ft_fit_win(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				loop_hook(t_env *e);
unsigned int	ft_strchri(char *stock, char c);
int				ft_set_stk(char *tmp, char **stk, char **buffer);
int				get_next_line(const int fd, char **line);
int				ft_get_points(t_env *e);
int				ft_calc_points(t_env *e);
int				ft_putmap(t_env *e);
int				ft_readmap(t_env *e);
unsigned int	ft_get_color(int cp1, int cp2, int i, int delta);
void			ft_display_comments(t_env *e);

#endif
