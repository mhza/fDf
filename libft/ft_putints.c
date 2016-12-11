/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:39:40 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/28 17:44:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putints(int *tab, int size)
{
	int i;

	if (size)
	{
		i = -1;
		while (++i < size)
		{
			ft_putnbr(tab[i]);
			ft_putchar('\n');
		}
	}
}
