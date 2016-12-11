/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:41:27 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/11 16:48:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_putline(t_env *e, t_point *p1, t_point *p2)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double)(p2->y - p1->y) / (p2->x - p1->x);
	b = p1->y - a * p1->x;
	x = p1->x;
	while (x <= p2->x)
	{
		y = (int)(a * x + b);
		ft_draw(e->mlx, e->win, x, y);
		x++;
	}
}

static void	ft_join_points(t_env *e, t_point *p1, t_point *p2)
{
	int		t;

	if (p2->x > p1->x)
		ft_putline(e, p1, p2);
	else if (p2->x < p1->x)
		ft_putline(e, p2, p1);
	else
	{
		t = 0;
		while (t <= p2->y - p1->y)
		{
			ft_draw(e->mlx, e->win, p1->x, p1->y + t);
			t++;
		}
	}
}

void		ft_putmap(t_env *e, t_point *points, int i, int j)
{
	int		k;

	k = 0;
	while (k < i * j)
	{
		if (k % j != j - 1)
			ft_join_points(e, points + k, points + k + 1);
		if (k / j != i - 1)
			ft_join_points(e, points + k, points + k + j);
		k++;
	}
}
