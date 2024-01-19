/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:50:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/19 11:44:18 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v'))
		return (1);
	if ((c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
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
		if (is_white_space(c))
			return (0);
		if ((c == '+') || (c == '-'))
			return (0);
		i = 0;
		while (base[i] && (i < size))
		{
			if (c == base[i])
				return (0);
			i++;
		}
		size++;
	}
	return (size);
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
	int				sign;

	res = 0;
	bsize = check_conditions(base);
	if (bsize <= 1)
		return (0);
	while (*str && is_white_space(*str))
		str++;
	while (*str && ((*str == '+') || (*str == '-')))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (find_num(*str, base) != -1)
	{
		res = res * bsize + find_num(*str, base);
		str++;
	}
	if (sign % 2)
		return (res * (-1));
	else
		return (res);
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
