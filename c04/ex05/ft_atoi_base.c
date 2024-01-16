/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:50:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 17:57:04 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	powing(char *str, int bsize)
{
	int		i;
	int		pow;

	pow = 1;
	i = 0;
	while (str[i])
	{
		i++;
		pow *= bsize;
	}
	pow /= bsize;
	return (pow);
}

int	find_num(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	find_res(char *str, char *base, int pow, int bsize)
{
	int		res;
	int		i;

	res = 0;
	while (*str)
	{
		i = find_num(*str, base);
		if (i == -1)
			return (0);
		res += i * pow;
		str++;
		pow /= bsize;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int		bsize;
	int		res;
	int		pow;
	int		sign;

	bsize = check_conditions(base);
	if (bsize <= 1)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	pow = powing(str, bsize);
	res = find_res(str, base, pow, bsize);
	return (res * sign);
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi_base("189", "0123456789"));
	printf("%d\n", ft_atoi_base("10111101", "01"));
	printf("%d\n", ft_atoi_base("BD", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("nfv", "poneyvif"));
}
*/
