/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:52:05 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/03 15:12:51 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_realloc_ptstab(t_point **pts, t_point *point)
{
	unsigned int	i;
	unsigned int	nb_pts;
	t_point			**pts_tmp;

	nb_pts = 0;
	while (pts[nb_pts])
		nb_pts++;
	if (!(pts_tmp = (t_point**)malloc(sizeof(t_point*) * (nb_pts + 2))))
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		pts_tmp[i] = pts[i];
	free(pts);
	pts_tmp[i] = point;
	pts_tmp[i + 1] = NULL;
	return (pts_tmp);
}

t_point	*ft_realloc_pts(t_point *old, t_point point, int nb_pts)
{
	t_point			*new;
	int				i;

	if ((new = (t_point*)malloc(sizeof(t_point) * (nb_pts + 2))) == NULL)
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		new[i] = old[i];
	new[i] = point;
	ft_bzero((new + i + 1), sizeof(t_point));
	return (new);
}
