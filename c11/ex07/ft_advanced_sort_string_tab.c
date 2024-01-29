/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:59:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 16:17:52 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		max_loc;
	int		i;
	int		size;

	if (!tab)
		return ;
	size = 0;
	while (tab[size])
		size++;
	while (size > 0)
	{
		size--;
		max_loc = size;
		i = size;
		while (i > 0)
		{
			i--;
			if ((*cmp)(tab[i], tab[max_loc]) > 0)
				max_loc = i;
		}
		if (max_loc != size)
			ft_swap(tab + size, tab + max_loc);
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char **ary = (char **)malloc(sizeof(char *) * 4);
	ary[0] = "abd";
	ary[1] = "abd";
	ary[2] = "aba";
	ary[3] = 0;
	ft_advanced_sort_string_tab(ary, &ft_strcmp);
	int i = 0;
	while (ary[i])
		printf("%s ", ary[i++]);
}
*/
