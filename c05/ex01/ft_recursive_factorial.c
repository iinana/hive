/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:37:51 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 09:48:25 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>
int main(void)
{
	printf("10 => %d\n", ft_recursive_factorial(10));
	printf("0  => %d\n", ft_recursive_factorial(0));
	printf("-1 => %d\n", ft_recursive_factorial(-1));
	printf("5 => %d\n", ft_recursive_factorial(5));
}
*/
