/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:21:17 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 14:29:54 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
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

int	ft_find_next_prime(int nb)
{
	int	res;

	if (nb <= 2)
		return (2);
	res = nb;
	while (1)
	{
		if (is_prime(res))
			return (res);
		res++;
	}
}

/*
#include <stdio.h>
int main(void)
{
	printf("3 => %d\n", ft_find_next_prime(3));
	printf("4 => %d\n", ft_find_next_prime(4));
	printf("3921 => %d\n", ft_find_next_prime(3921));
	printf("-3 => %d\n", ft_find_next_prime(-3));
}
*/
