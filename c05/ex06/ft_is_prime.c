/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:50:50 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 14:19:47 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	n = 2;
	while (n < nb)
	{
		if ((nb % n) == 0)
			return (0);
		n++;
	}
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("29  => %d\n", ft_is_prime(29));
	printf("787 => %d\n", ft_is_prime(787));
	printf("4   => %d\n", ft_is_prime(4));
}
*/
