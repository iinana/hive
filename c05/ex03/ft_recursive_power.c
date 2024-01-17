/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:57:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 10:42:30 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, --power));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("2, 6 => %d\n", ft_recursive_power(2, 6));
	printf("3, 0 => %d\n", ft_recursive_power(3, 0));
	printf("0, 3 => %d\n", ft_recursive_power(0, 3));
	printf("10, 5 => %d\n", ft_recursive_power(10, 5));
	printf("3, 10 => %d\n", ft_recursive_power(3, 10));
}
*/
