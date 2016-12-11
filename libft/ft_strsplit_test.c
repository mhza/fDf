/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:55:28 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/21 17:01:31 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	if (str && str[0])
	{
		write(1, &str[0], 1);
		ft_putstr(str + 1);
	}
}

static char	**ft_addneww(char const *s, char c, char **tab,
	unsigned int tab_size)
{
	unsigned int				i;
	int j;
	unsigned int	neww_len;
	char			*neww;
	char			**tab_tmp;

	j = '0' + tab_size;
	write(1, &j, 1);
	ft_putstr(" ft_addneww\n");
	if(ft_strchr(s, c))
		neww_len = ft_strchr(s, c) - s;
	else
		neww_len = ft_strlen(s);
	if ((neww = ft_strnew(neww_len)))
		neww = ft_strncpy(neww, s, neww_len);
	ft_putstr(neww);
	ft_putstr("\n");
	if ((tab_tmp = (char**)malloc(sizeof(char*) * (tab_size + 1))))
	{
		i = -1;
		ft_putstr("in tab_tmp malloc \n ");
		while (++i < tab_size - 1)
		{
			ft_putstr("in while  \n");
			ft_putstr(*(tab + i));
			ft_putstr("\n");
			*(tab_tmp + i) = ft_strdup(*(tab + i));
		}
		ft_putstr("after tab_tmp malloc \n ");
		*(tab_tmp + tab_size - 1) = ft_strdup(neww);
		*(tab_tmp + tab_size) = 0;
		ft_putstr(tab_tmp[tab_size - 1]);
		ft_putstr("\n");
		if (neww && neww[0])
			ft_strclr(neww);
		if (tab_size > 1 && tab && tab[0])
			ft_strdel(tab);
	}
	return (tab_tmp);
}

static char	**ft_stotab(char const *s, char c, char **tab,
	unsigned int tab_size)
{
	ft_putstr("ft_stotab\n");
	if (s[0] && s[0] == c)
	{
		ft_putstr("s[0] == c\n");
		ft_putstr((char*)s);
		ft_putstr("\n");
		return (ft_stotab(s + 1, c, tab, tab_size));
	}ft_putstr("ft_stotab\n");
	if (s[0] && s[0] != c && ft_strchr(s, c))
	{
		ft_putstr("s[0] != c\n");
		return (ft_stotab(ft_strchr(s, c), c,
		ft_addneww(s, c, tab, tab_size + 1), tab_size + 1));
	}ft_putstr("ft_stotab\n");
	if (s[0] && s[0] != c && ft_strchr(s, c) == NULL)
	{
		ft_putstr("(sft_strchr(s, c) + 1) == NULL\n");
		return (ft_addneww(s, c, tab, tab_size + 1));
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	tab_size;
	char			**tab;

	ft_putstr("ft_strsplit\n");
	tab_size = 0;
	tab = (char**)malloc(sizeof(char*));
	if (s && s[0] && c && tab != NULL)
		tab = ft_stotab(s, c, tab, tab_size);
	return (tab);
}

int			main(void)
{
	int i = -1;
	char str[50] = "**.lord**bjk\0";

	char **tab = ft_strsplit(str, '*');
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putstr("+\n");
	}

	return (1);
}

// static int		ft_wcount(char const *s, char c)
// {
// 	int count;
// 	int i;
//
// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c && s[i])
// 			i++;
// 		if (s[i] != c && s[i])
// 			count++;
// 	}
// 	return (count);
// }
//
// char			**ft_strsplit(char const *s, char c)
// {
// 	char			**tab;
// 	char			*str;
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	count;
//
// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] && s[i] != c)
// 		{
// 			count++;
// 			if ((tab = count(tab, count)) == NULL)
// 				return (NULL);
// 		}
// 		j = 0;
// 		while (s[i + j] && s[i + j] != c)
// 		{
// 			str = ft_realloc((char*)s + i, j);
// 			j++;
// 		}
// 		str[j] = '\0';
// 		tab[count] = str;
// 		i++;
// 	}
// 	tab[i] = 0;
// 	return (tab);
// }
