/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:41:27 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/03 15:12:11 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_printline_x(t_line *line, t_env *e)
{
	int	i;
	int	cumul;

	cumul = ABS(line->dx) / 2;
	i = 1;
	e->is_decr = line->dx > 0 ? 1 : -1;
	while (i <= ABS(line->dx))
	{
		line->x = line->dx > 0 ? line->x + 1 : line->x - 1;
		cumul += ABS(line->dy);
		if (cumul >= ABS(line->dx))
		{
			cumul -= ABS(line->dx);
			line->y = line->dy > 0 ? line->y + 1 : line->y - 1;
		}
		mlx_pixel_put(e->mlx, e->win, e->tr + line->x, e->td + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * i, line->dx));
		i++;
	}
}

static void		ft_printline_y(t_line *line, t_env *e)
{
	int	i;
	int	cumul;

	cumul = ABS(line->dy) / 2;
	i = 1;
	e->is_decr = line->dy > 0 ? 1 : -1;
	while (i <= ABS(line->dy))
	{
		line->y = line->dy > 0 ? line->y + 1 : line->y - 1;
		cumul += ABS(line->dx);
		if (cumul >= ABS(line->dy))
		{
			cumul -= ABS(line->dy);
			line->x = line->dx > 0 ? line->x + 1 : line->x - 1;
		}
		mlx_pixel_put(e->mlx, e->win, e->tr + line->x, e->td + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * i, line->dy));
		i++;
	}
}

static void		ft_join_points(t_env *e, t_point *p1, t_point *p2)
{
	t_line	line;

	e->is_decr = 0;
	line.x = p1->x;
	line.y = p1->y;
	line.dx = p2->x - p1->x;
	line.dy = p2->y - p1->y;
	line.cp1 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p1->z - e->zmin);
	line.cp2 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p2->z - e->zmin);
	mlx_pixel_put(e->mlx, e->win, e->tr + line.x, e->td + line.y,
	ft_get_color(line.cp1, 0, 0, 1));
	if (ABS(line.dx) > ABS(line.dy))
		ft_printline_x(&line, e);
	else
		ft_printline_y(&line, e);
}

static void		ft_before_draw(t_env *e, t_point **points, int i)
{
	int		j;
	int		k;
	t_point	nullpt;

	ft_bzero(&nullpt, sizeof(t_point));
	j = 0;
	while ((!i && !j) || ft_memcmp(&points[i][j], &nullpt, sizeof(t_point)))
	{
		if (ft_memcmp(&points[i][j + 1], &nullpt, sizeof(t_point)))
			ft_join_points(e, &points[i][j], &points[i][j + 1]);
		k = 0;
		while (points[i + 1] &&
			ft_memcmp(&points[i + 1][k], &nullpt, sizeof(t_point)))
			k++;
		if (points[i + 1] && j <= k &&
			ft_memcmp(&points[i + 1][j], &nullpt, sizeof(t_point)))
			ft_join_points(e, &points[i][j], &points[i + 1][j]);
		j++;
	}
}

int				ft_putmap(t_env *e)
{
	int		i;
	t_point	**points;

	i = 0;
	if ((points = e->points_tab) == NULL)
		return (-1);
	while (points[i])
	{
		ft_before_draw(e, points, i);
		i++;
	}
	ft_display_comments(e);
	return (0);
}
