/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:49:26 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 10:00:12 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	res = 1;
	while (power-- > 0)
		res *= nb;
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("2, 6 => %d\n", ft_iterative_power(2, 6));
	printf("3, 0 => %d\n", ft_iterative_power(3, 0));
	printf("0, 3 => %d\n", ft_iterative_power(0, 3));
	printf("10, 5 => %d\n", ft_iterative_power(10, 5));
	printf("3, 10 => %d\n", ft_iterative_power(3, 10));
}
*/
