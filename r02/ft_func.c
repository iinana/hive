/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:54:00 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 18:06:07 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_on(char **num, int *digit, int gap)
{
	(*num) += gap;
	(*digit) -= gap;
}

void	ft_putstr(char *str)
{
	if (!*str)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	while (*str)
		write(1, str++, 1);
}

int	count_digits(char **num)
{
	int		count;

	while (**num == ' ')
		++(*num);
	while (**num == '0')
	{
		if (*(*num + 1) == 0)
			return (1);
		++(*num);
	}
	count = 0;
	while ((*num)[count] && (*num)[count] >= '0' && (*num)[count] <= '9')
		count++;
	return (count);
}

char	**init_ary(int	size)
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
