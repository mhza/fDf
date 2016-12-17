/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:44:47 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/16 15:30:44 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		ft_calc_points(t_env *e)
{
	int		i;
	t_point	*points;

	i = 0;
	if ((points = e->points) == NULL)
		return (-1);
	while (i < e->col * e->ln)
	{
		if (points[i].z > e->zmax)
			e->zmax = points[i].z;
		if (points[i].z < e->zmin)
			e->zmin = points[i].z;
		ft_set_coordinates(e, &points[i]);
		if (points[i].x > e->xmax)
			e->xmax = points[i].x;
		if (points[i].x < e->xmin)
			e->xmin = points[i].x;
		if (points[i].y > e->ymax)
			e->ymax = points[i].y;
		if (points[i].y < e->ymin)
			e->ymin = points[i].y;
		i++;
	}
	return (0);
}

int		ft_get_points(t_env *e)
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
		{
			(e->points + i * e->col + j)->x0 = j;
			(e->points + i * e->col + j)->y0 = i;
			(e->points + i * e->col + j)->z = ft_atoi(axe_x[j]);
			j++;
		}
		i++;
	}
	return (0);
}
