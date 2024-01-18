/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:58:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/18 14:10:08 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if (c == ' ' | c == '\t' | c == '\n')
		return (1);
	if (c == '\f' | c == '\v' | c == '\r')
		return (1);
	else
		return (0);
}

int	find_sign(char **str)
{
	int		count;

	count = 0;
	while (**str && ((**str < '0') || (**str > '9')))
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

int	find_num(long int pow, char *str)
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
	int			len;
	int			sign;
	int			res;
	long int	pow;

	while (is_white_space(*str))
		str++;
	sign = find_sign(&str);
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
#include <stdio.h>
int	main(void)
{
	char s1[] = " \t--+--+1234ab567";
	printf("%s: %d\n", s1, ft_atoi(s1));
	printf("%s: %d\n", "1325632167", ft_atoi("1325632167"));
	printf("%s: %d\n", "-2147483648", ft_atoi("-2147483648"));
}
*/
