/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:51:40 by injung            #+#    #+#             */
/*   Updated: 2024/01/30 16:39:15 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *str, int len)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	count_line(int infile)
{
	char	c;
	int		len;

	len = 0;
	while (read(infile, &c, 1) > 0 && c != '\n')
		len++;
	return (len);
}
