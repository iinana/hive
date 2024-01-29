/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:29:39 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 14:02:26 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *nb)
{
	int		res;

	res = 0;
	while (*nb && *nb >= '0' && *nb <= '9')
	{
		res = res * 10 + (*nb - '0');
		nb++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	int		pow;
	char	temp;

	pow = 1;
	while (n / pow >= 10)
		pow *= 10;
	while (pow > 0)
	{
		temp = n / pow + '0';
		write(1, &temp, 1);
		n = n % pow;
		pow /= 10;
	}
}
