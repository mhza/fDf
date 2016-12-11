/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:44:47 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/11 16:49:44 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_set_x(int x, int y)
{
	return (0.8 * x - 0.4 * y);
}

static int		ft_set_y(int x, int y, int z)
{
	return (0.4 * x + 0.2 * y - z);
}

t_point			*ft_get_points(t_env *e, t_point *points, int i, int j)
{
	char	**axe_y;
	char	**axe_x;
	int		k;

	k = j;
	i = 0;
	if ((axe_y = ft_strsplit(e->map, '\n')) == NULL)
		return (NULL);
	while (axe_y[i] != 0)
	{
		if ((axe_x = ft_strsplit(axe_y[i], ' ')) == NULL)
			return (NULL);
		j = 0;
		while (axe_x[j] != 0)
		{
			(points + i * k + j)->x = ft_set_x(500 + 50 * j, 230 + 50 * i);
			(points + i * k + j)->y = ft_set_y(500 + 50 * j, 230 + 50 * i,
				ft_atoi(axe_x[j]));
			(points + i * k + j)->z = ft_atoi(axe_x[j]);
			j++;
		}
		i++;
	}
	return (points);
}
