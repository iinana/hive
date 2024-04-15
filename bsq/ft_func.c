/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:51:40 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 18:12:10 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

unsigned int	ft_atoi(char *str, int len)
{
	int				i;
	unsigned int	res;

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

unsigned int	count_line(int infile)
{
	char	c;
	unsigned int		len;

	len = 0;
	while (read(infile, &c, 1) > 0 && c != '\n')
		len++;
	return (len);
}

void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = *src;
		i++;
		src++;
	}
}
