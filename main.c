/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:49:50 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/11 16:45:34 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_readmap(t_env *e)
{
	char	**axe_y;
	char	**axe_x;
	t_point	*points;
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
	if (!(points = (t_point*)malloc(sizeof(t_point) * i * j + 1)))
		return (-1);
	points = ft_get_points(e, points, i, j);
	ft_putmap(e, points, i, j);
	return (0);
}

int		ft_call_mlx(char *map)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2500, 2500, "fDf42");
	e.map = map;
	mlx_expose_hook(e.win, ft_readmap, &e);
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
		if (ret == -1 || !map || !(tmp = ft_strjoin(map, buffer)) ||
		ft_set_stk(tmp, &map, &buffer) == -1)
			return (0);
	}
	ft_call_mlx(map);
	return (0);
}
