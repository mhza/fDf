/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/11 16:40:08 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(void *mlx, void *win, int x, int y)
{
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

int		expose_hook(t_env *e)
{
	if (!e)
		return (-1);
	//ft_draw(e->mlx, e->win, e->x, e->y);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (e && keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (!e)
		return (0);
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		loop_hook(t_env *e)
{
	mlx_loop(e->mlx);
	return (0);
}
