/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:43:05 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 11:25:17 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("10 => %d\n", ft_fibonacci(10));
	printf("45 => %d\n", ft_fibonacci(45));
	printf("2  => %d\n", ft_fibonacci(2));
}
*/
