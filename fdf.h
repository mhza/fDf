/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:50:09 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/11 16:48:35 by mhaziza          ###   ########.fr       */
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
# define BUFF_SIZE 1000

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	char	*map;
}				t_env;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

void			ft_draw(void *mlx, void *win, int x, int y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				loop_hook(t_env *e);
unsigned int	ft_strchri(char *stock, char c);
int				ft_set_stk(char *tmp, char **stk, char **buffer);
int				get_next_line(const int fd, char **line);
t_point			*ft_get_points(t_env *e, t_point *points, int i, int j);
void			ft_putmap(t_env *e, t_point *points, int i, int j);
#endif
