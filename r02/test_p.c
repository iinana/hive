/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:25:10 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 11:31:21 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	write_num(char *num, dictionary dict)
{
	int		digit;

	digit = count_digits(&num);
	if (digit <= 0)
		return (0);
	if (digit == 1 && *num == '0')
	{
		ft_putstr((dict.num)[*num - '0']);
		return (1);
	}
	while (*num && *num >= '0' && *num <= '9' && digit > 0)
	{
		if (digit == 1 && *num != '0')
		{
			ft_putstr((dict.num)[*num - '0']);
			write(1, "\n", 1);
		}
		else if (digit == 2 && *num != 0)
		{
			ft_putstr((dict.num)[(*num - '0') * 10]);
			if (*(num +1) != '0')
				write(1, " ", 1);
		}
		else if (digit == 3 && *num != '0')
		{
			ft_putstr((dict.num)[*num - '0']);
			write(1, " ", 1);
			ft_putstr((dict.digit)[3]);
			write(1, " ", 1);
		}
		else if (dict.digit[digit] && digit % 3 == 1 && *num != '0')
		{
			ft_putstr((dict.num)[*num - '0']);
			write(1, " ", 1);
			ft_putstr((dict.digit)[digit]);
			write(1, " ", 1);
		}
		else if (dict.digit[digit - 1] && *num != 0)
		{
			ft_putstr((dict.num)[(*num - '0') * 10]);
			write(1, " ", 1);
		}
		else if (dict.digit[digit -2] && *num != '0')
		{
			ft_putstr((dict.num)[*num - '0']);
			write(1, " ", 1);
			ft_putstr((dict.digit)[100]);
			write(1, " ", 1);
		}
		digit--;
		num++;
	}
	return (1);
}
