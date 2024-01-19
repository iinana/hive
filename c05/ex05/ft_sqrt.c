/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:25:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/19 20:25:48 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int				res;
	long long int	temp;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	temp = 1;
	res = 1;
	while (res < nb)
	{
		temp = res * res;
		if (temp > nb)
			return (0);
		if (temp == nb)
			return (res);
		res++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <math.h>
int main(void)
{
	printf("-2782 => %d %.2f\n", ft_sqrt(-2782), sqrt(-2782));
	printf("33304441 => %d %.2f\n", ft_sqrt(33304441), sqrt(33304441));
	printf("1746868161 => %d %.2f\n", ft_sqrt(1746868161), sqrt(1746868161));
	printf("206755641 => %d %.2f\n", ft_sqrt(206755641), sqrt(206755641));
	printf("635444571 => %d %.2f\n", ft_sqrt(635444571), sqrt(635444571));
	printf("86787856 => %d %.2f", ft_sqrt(86787856), sqrt(86787856));
}
*/
