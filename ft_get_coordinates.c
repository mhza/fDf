/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:44:47 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/03 15:18:33 by mhaziza          ###   ########.fr       */
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

void	ft_set_coordinates(t_env *e, t_point *points)
{
	int		x;
	int		y;
	int		z;

	x = e->zoom * points->x0;
	y = e->zoom * points->y0;
	z = e->zoom / e->manz * points->z;
	if (e->is_iso)
	{
		points->x = e->c1 * x - e->c2 * y;
		points->y = e->piv * (e->c1 / 2 * x + e->c2 / 2 * y) - z;
	}
	else
	{
		points->x = x - e->c1 * z;
		points->y = y - e->c1 / 2 * z;
	}
}

void	ft_set_struct(t_env *e, t_point *point)
{
	if (point->z > e->zmax)
		e->zmax = point->z;
	if (point->z < e->zmin)
		e->zmin = point->z;
	ft_set_coordinates(e, point);
	if (point->x > e->xmax)
		e->xmax = point->x;
	if (point->x < e->xmin)
		e->xmin = point->x;
	if (point->y > e->ymax)
		e->ymax = point->y;
	if (point->y < e->ymin)
		e->ymin = point->y;
}

int		ft_calc_points(t_env *e)
{
	int		i;
	int		j;
	t_point	**points;
	t_point	nullpt;

	ft_bzero(&nullpt, sizeof(t_point));
	i = 0;
	if ((points = e->points_tab) == NULL)
		return (-1);
	while (points[i])
	{
		j = 0;
		while ((!i && !j) || ft_memcmp(&points[i][j], &nullpt, sizeof(t_point)))
		{
			ft_set_struct(e, &points[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
