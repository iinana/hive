/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:56:55 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 09:47:52 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		res;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	printf("10 => %d\n", ft_iterative_factorial(10));
	printf("0  => %d\n", ft_iterative_factorial(0));
	printf("-1 => %d\n", ft_iterative_factorial(-1));
	printf("5  => %d\n", ft_iterative_factorial(5));
}
*/
