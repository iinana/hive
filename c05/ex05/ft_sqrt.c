/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:25:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 12:48:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	res = 1;
	while (res < nb)
	{
		if ((nb % res == 0) && (res == (nb / res)))
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
	printf("256 => %d %.2f\n", ft_sqrt(256), sqrt(256));
	printf("-38 => %d %.2f\n", ft_sqrt(-38), sqrt(-38));
	printf("2   => %d %.2f\n", ft_sqrt(2), sqrt(2));
	printf("64  => %d %.2f\n", ft_sqrt(64), sqrt(64));
	printf("169 => %d %.2f\n", ft_sqrt(169), sqrt(169));
	printf("0   => %d %.2f", ft_sqrt(0), sqrt(0));
}
*/
