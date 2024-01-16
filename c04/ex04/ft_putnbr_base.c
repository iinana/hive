/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:01:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 17:51:35 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_conditions(char *base)
{
	int		size;
	char	c;
	int		i;

	size = 0;
	while (base[size])
	{
		c = base[size];
		if ((c == '+') || (c == '-') || (c == ' '))
			return (0);
		i = size + 1;
		while (base[i])
		{
			if (c == base[i])
				return (0);
			i++;
		}
		size++;
	}
	return (size);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		bsize;
	int		pow;

	bsize = check_conditions(base);
	if (bsize <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	pow = 1;
	while (nbr / pow >= bsize)
		pow *= bsize;
	while (pow > 0)
	{
		write(1, &base[nbr / pow], 1);
		nbr = nbr % pow;
		pow /= bsize;
	}
}


int main(void)
{
	ft_putnbr_base(-189, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-189, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-189, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-189, "poneyvif");
	ft_putnbr_base(-189, "01234563789");
}

