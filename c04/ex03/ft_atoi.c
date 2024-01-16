/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:58:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 15:54:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	find_num(int pow, char *str)
{
	int		res;

	res = 0;
	while (pow >= 10)
	{
		pow /= 10;
		res += ((*str - '0') * pow);
		str++;
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int		len;
	int		sign;
	int		res;
	int		pow;

	sign = 1;
	while (*str && ((*str < '0') || (*str > '9')))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	pow = 1;
	len = 0;
	while (str[len] && ((str[len] >= '0') && (str[len] <= '9')))
	{
		len++;
		pow *= 10;
	}
	res = find_num(pow, str);
	return (sign * res);
}

/*
int	main(void)
{
	char s1[] = " ---+--+1234ab567";
	printf("%s: %d\n", s1, ft_atoi(s1));
}
*/
