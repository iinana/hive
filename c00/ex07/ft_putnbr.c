/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:52:36 by injung            #+#    #+#             */
/*   Updated: 2024/01/10 21:56:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		pow;
	int		count;
	int		temp;
	char	res[11];

	pow = 1;
	count = 0;
	if (nb < 0)
	{
		res[0] = '-';
		count++;
		nb = -nb;
	}
	while ((nb / pow) > 9)
		pow *= 10;
	while (pow > 0)
	{
		temp = nb / pow;
		nb -= temp * pow;
		res[count] = temp + 48;
		count++;
		pow /= 10;
	}
	write(1, res, count);
}
