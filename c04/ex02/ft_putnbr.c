/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:42:12 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 11:57:27 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		pow;
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	pow = 1;
	while ((nb / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		c = (nb / pow) + '0';
		nb = nb % pow;
		write(1, &c, 1);
		pow /= 10;
	}
}

/*int	main(void)
{
	write(1, "42: ", 4);
	ft_putnbr(42);
	write(1, "\n-42: ", 5);
	ft_putnbr(-42);
	write(1, "\n0: ", 5);
	ft_putnbr(0);
	write(1, "\n34293: ", 8);
	ft_putnbr(34293);
	write(1, "\n390100 ", 9);
	ft_putnbr(390100);
	write(1, "\n-2147483648: ", 13);
	ft_putnbr(-2147483648);
} */
