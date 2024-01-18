/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:50:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/18 17:24:07 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_num(char c, char *base);

int	find_sign(char **str, char *base)
{
	int		count;

	while (**str)
	{
		if (**str == ' ' | **str == '\t' | **str == '\n')
			++(*str);
		else if (**str == '\f' | **str == '\v' | **str == '\r')
			++(*str);
		else
			break ;
	}
	count = 0;
	while (**str && (find_num(**str, base) == -1))
	{
		if (**str == '-')
			count++;
		else if (**str != '+')
			return (0);
		++(*str);
	}
	if (count % 2)
		return (-1);
	else
		return (1);
}

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

long int	powing(char *str, long int bsize, char *base)
{
	int				i;
	long int		pow;

	pow = 1;
	i = 0;
	while (str[i] && (find_num(str[i], base) != -1))
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

int	ft_atoi_base(char *str, char *base)
{
	int				bsize;
	int				res;
	long int		pow;
	int				sign;
	int				i;

	bsize = check_conditions(base);
	if (bsize <= 1)
		return (0);
	sign = find_sign(&str, base);
	if (sign == 0)
		return (0);
	pow = powing(str, bsize, base);
	res = 0;
	while (*str)
	{
		i = find_num(*str, base);
		if (i == -1)
			break ;
		res += i * pow;
		str++;
		pow /= bsize;
	}
	return (res * sign);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi_base("  -+-1435i3", "0123456789"));
	printf("%d\n", ft_atoi_base("10111101", "01"));
	printf("%d\n", ft_atoi_base("BD", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("nfav", "poneyvif"));
}
*/
