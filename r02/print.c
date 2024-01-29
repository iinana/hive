/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:25:10 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 17:01:37 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	write_num(char *num, dictionary dict)
{
	int		digit;

	digit = count_digits(&num);
	if (digit <= 0)
		return (0);
	if (digit == 1)
	{
		ft_putstr((dict.num)[*num - '0']);
		write(1, "\n", 1); 
		return (1);
	}
	if (!recur_write(num, digit, dict))
		return (0);
	return (1);
}

int	recur_write(char *num, int digit, dictionary dict)
{
	int		i;
	int		space;

	if (digit <= 0)
		return (1);
	i = digit;
	space = 0;
	while (*num && digit > 0)
	{
		if (digit % 3 == 0)
		{
			if (digit < i)
				space = 1;
			if (!print_hundred(num, digit, dict, space))
				return (0);
			digit -= 3;
			num += 3;
		}
		else if (digit % 3 == 2)
		{
			if (!print_ten(num, digit, dict, 2))
				return (0);
			digit -= 2;
			num += 2;
		}
		else if (digit % 3 == 1)
		{
			if (!print_one(num, digit, dict, 2))
				return (0);
			digit--;
			num++;
		}
	}
	write(1, "\n", 1);
	return (1);
}

int	print_hundred(char *num, int digit, dictionary dict, int space)
{
	if (*num == '0')
	{
		if (print_ten(num + 1, digit - 1, dict, 0))
			return (1);
		return (0);
	}
	if (space == 1)
		write(1, " ", 1);
	ft_putstr((dict.num)[*num - '0']);
	write(1, " ", 1);
	ft_putstr((dict.digit)[3]);
	if (print_ten(num + 1, digit - 1, dict, 1))
		return (1);
	return (0);
}

int	print_ten(char *num, int digit, dictionary dict, int flag)
{
	int		temp;

	if (*num == '0')
	{
		if (print_one(num + 1, digit - 1, dict, flag))
			return (1);
		return (0);
	}
	if (*num == '1')
	{
		temp = (*num - '0') * 10 + (*(num + 1) - '0');
		if (flag != 2)
			write(1, " ", 1);
		ft_putstr((dict.num)[temp]);
		if (print_one("0", digit - 1, dict, 1))
			return (1);
		return (0);
	}
	if (flag != 2)
		write(1, " ", 1);
	ft_putstr((dict.num)[(*num - '0') * 10]);
	if (print_one(num + 1, digit - 1, dict, 1))
		return (1);
	return (0);
}

int print_one(char *num, int digit, dictionary dict, int flag)
{
	if (*num == '0' && flag == 0)
		return (1);
	if (*num == '0' && flag == 1)
	{
		if (digit == 1)
			return (1);
		if (digit % 3 == 1)
		{
			if (flag != 2)
				write(1, " ", 1);
			ft_putstr((dict.digit)[digit]);
			return (1);
		}
		else
			return (0);
	}
	if (flag != 2)
		write(1, " ", 1);
	ft_putstr((dict.num)[(*num) - '0']);
	if (digit != 1)
	{
		write(1, " ", 1);
		ft_putstr((dict.digit)[digit]);
	}
	return (1);
}
