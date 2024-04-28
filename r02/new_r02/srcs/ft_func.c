/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:54:00 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 12:57:13 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// initialize string array in dictionary with zero
char	**init_ary(int size)
{
	char	**ary;
	int		i;

	ary = (char **)malloc(sizeof(char *) * size);
	if (ary == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		ary[i++] = 0;
	return (ary);
}

int	is_printable(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	else
		return (0);
}
