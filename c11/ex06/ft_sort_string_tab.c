/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:05:37 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 16:09:23 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s1[i])
		return (1);
	return (0);
}

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[max_loc]))
				max_loc = i;
		}
		if (max_loc != size)
			ft_swap(tab + max_loc, tab + size);
	}
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
	ft_sort_string_tab(ary);

	int i = 0;
	while (ary[i])
		printf("%s ", ary[i++]);
}
*/
