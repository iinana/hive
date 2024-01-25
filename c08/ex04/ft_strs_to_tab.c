/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:05:03 by injung            #+#    #+#             */
/*   Updated: 2024/01/25 08:47:00 by injung           ###   ########.fr       */
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
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
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

	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s[i].str = av[i];
		s[i].size = ft_strlen(av[i]);
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
	t_stock_str *s = ft_strs_to_tab(argc-1, argv+1);
	while (s->str)
	{
		printf("%d %s %s\n", s->size, s->str, s->copy);
		s++;
	}
}
*/
