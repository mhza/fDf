/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/16 15:53:14 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_center_ifntrans(t_env *e)
{
	e->ymax = 0;
	e->ymin = 0;
	e->xmax = 0;
	e->xmin = 0;
	ft_calc_points(e);
	ft_fit_win(e);
	return (1);
}

int		key_hook(int keycode, t_env *e)
{
	if (((e->divpi + M_PI / 15) < (M_PI / 2) && keycode == 84) ||
		(((e->divpi - M_PI / 15)) > 0 && keycode == 83))
	{
		e->divpi = keycode == 84 ? e->divpi + M_PI / 15 : e->divpi - M_PI / 15;
		e->c1 = (float)sin(e->divpi);
		e->c2 = (float)cos(e->divpi);
	}
	if ((keycode == 47 && e->manz >= 2) || keycode == 43)
		e->manz = keycode == 43 ? e->manz + 1 : e->manz - 1;
	if (keycode == 85 || keycode == 88)
		e->piv = keycode == 85 ? e->piv + 0.3 : e->piv - 0.3;
	if (keycode == 123 || keycode == 124)
		e->tr = keycode == 124 ? e->tr + WIN_X / 10 : e->tr - WIN_X / 10;
	if (keycode == 125 || keycode == 126)
		e->td = keycode == 125 ? e->td + WIN_Y / 10 : e->td - WIN_Y / 10;
	if ((e->zoom > 1 && keycode == 78) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom / 2 : e->zoom * 2;
	if (keycode == 49)
		e->is_iso = e->is_iso == 1 ? 0 : 1;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	if (ft_calc_points(e) != -1 && ((keycode > 100) || ft_center_ifntrans(e)))
		ft_putmap(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (!e || !button || !x || !y)
		return (0);
	return (0);
}

int		loop_hook(t_env *e)
{
	mlx_loop(e->mlx);
	return (0);
}

void	ft_display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF, "Quit    = ESC");
	mlx_string_put(e->mlx, e->win, 10, 15, 0xFFFFFF, "- +    = zoom");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "< >    = manage z");
	mlx_string_put(e->mlx, e->win, 10, 45, 0xFFFFFF, "1 2    = horiz rot");
	mlx_string_put(e->mlx, e->win, 10, 60, 0xFFFFFF, "3 6    = vertic rot");
	mlx_string_put(e->mlx, e->win, 10, 75, 0xFFFFFF, "<- ->  = horiz tr");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF, "^ v    = vertic tr");
	mlx_string_put(e->mlx, e->win, 10, 105, 0xFFFFFF, "' '    = switch proj");
}
