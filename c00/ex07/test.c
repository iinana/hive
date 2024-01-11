/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:52:36 by injung            #+#    #+#             */
/*   Updated: 2024/01/11 17:39:23 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	powing(int nb)
{
	int		pow;

	pow = 1;
	while ((nb / pow) > 9)
		pow *= 10;
	return (pow);
}

int	check_condition(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int		pow;
	int		count;
	int		temp;
	char	res[11];

	count = 0;
	if (check_condition(nb) == 1)
		return ;
	if (nb < 0)
	{
		res[0] = '-';
		count++;
		nb = -nb;
	}
	pow = powing(nb);
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

int main() {
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(10000);
}
