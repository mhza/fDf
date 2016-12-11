/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:09:59 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/24 14:30:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_addneww(char const *s, char c, t_list *list)
{
	unsigned int	i;
	unsigned int	neww_len;
	char			*neww;
	t_list			*new_list;

	if (ft_strchr(s, c) != NULL)
		neww_len = ft_strchr(s, c) - s;
	else
		neww_len = ft_strlen(s);
	if ((neww = ft_strnew(neww_len)))
		neww = ft_strncpy(neww, s, neww_len);
	if ((new_list = ft_lstnew(neww, neww_len)))
	{
		new_list->next = list;
		if (neww && neww[0])
			ft_strclr(neww);
	}
	return (new_list);
}

static char	**ft_stotab(char const *s, char c, t_list *list)
{
	if (s[0] && s[0] == c)
		return (ft_stotab(s + 1, c, list));
	if (s[0] && s[0] != c && ft_strchr(s, c))
		return (ft_stotab(ft_strchr(s, c), c, ft_addneww(s, c, tab)));
	if (s[0] && s[0] != c && ft_strchr(s, c) == NULL)
		return (ft_addneww(s, c, list));
	return (list);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	tab_size;
	t_list			*begin_list;
	int				i;

	tab_size = 0;
	if (!s || !c)
		return (NULL);
	if ((begin_list = (char**)malloc(sizeof(t_list*))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[0] || i == (int)ft_strlen(s))
		return (0);
	begin_list = ft_stotab(s, c, begin_list);
	return (begin_list);
}
