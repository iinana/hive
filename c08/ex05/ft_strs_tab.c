/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:05:03 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 11:29:43 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src, int size)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s;
	int			i;

	if (ac <= 0 || av == 0)
		return (0);
	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s)
		return (0);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i], s[i].size);
		i++;
	}
	s[i].str = 0;
	return (s);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stock_str *s = ft_strs_to_tab(argc, argv);
	while (s->str)
	{
		printf("%d %s %s\n", s->size, s->str, s->copy);
		s++;
	}
}
*/
