/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:49:50 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/16 15:53:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fit_win(t_env *e)
{
	int is_fit;

	is_fit = 1;
	if (e->xmax - e->xmin > WIN_X || e->ymax - e->ymin > WIN_Y)
		is_fit = 0;
	else
	{
		e->tr = (WIN_X - (float)(e->xmax - e->xmin)) / 2 + ABS(e->xmin);
		e->td = (WIN_Y - (float)(e->ymax - e->ymin)) / 2 + ABS(e->ymin);
	}
	return (is_fit);
}

int		ft_readmap(t_env *e)
{
	char	**axe_y;
	char	**axe_x;
	int		i;
	int		j;

	i = 0;
	if ((axe_y = ft_strsplit(e->map, '\n')) == NULL)
		return (-1);
	while (axe_y[i] != 0)
	{
		if ((axe_x = ft_strsplit(axe_y[i], ' ')) == NULL)
			return (-1);
		j = 0;
		while (axe_x[j] != 0)
			j++;
		i++;
	}
	if (!(e->points = (t_point*)malloc(sizeof(t_point) * i * j + 1)))
		return (-1);
	e->ln = i;
	e->col = j;
	return (0);
}

void	ft_init_env(t_env *e, char *map)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fDf42");
	e->map = map;
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->is_iso = 1;
	e->tr = 1000;
	e->td = 100;
	e->piv = 1;
	e->manz = 10;
	e->zmax = 0;
	e->zmin = 0;
	e->ymax = 0;
	e->ymin = 0;
	e->xmax = 0;
	e->xmin = 0;
	e->zoom = 20;
}

int		ft_call_mlx(char *map)
{
	t_env	e;

	ft_init_env(&e, map);
	if (ft_readmap(&e) != -1 && ft_get_points(&e) != -1 &&
		ft_calc_points(&e) != -1)
	{
		while (e.zoom > 1 && !ft_fit_win(&e))
		{
			e.ymax = 0;
			e.ymin = 0;
			e.xmax = 0;
			e.xmin = 0;
			e.zoom /= 2;
			ft_calc_points(&e);
		}
		mlx_expose_hook(e.win, ft_putmap, &e);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	loop_hook(&e);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	*map;
	int		ret;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if ((map = ft_strnew(BUFF_SIZE)) == NULL)
		return (0);
	if ((buffer = ft_strnew(BUFF_SIZE)) == NULL)
		return (0);
	ret = 1;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (ret == -1 || !map || !(tmp = ft_strjoin(map, buffer)) ||
		ft_set_stk(tmp, &map, &buffer) == -1)
			return (0);
	}
	ft_call_mlx(map);
	return (0);
}
