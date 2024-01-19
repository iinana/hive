/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/19 19:26:54 by injung           ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int		res;
	int		sign;

	res = 0;
	while (*str && is_white_space(*str))
		str++;
	sign = 0;
	while (*str && ((*str == '+') || (*str == '-')))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
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
	char s1[] = " \t---+--+1234ab567";
	printf("%s: %d\n", s1, ft_atoi(s1));
	printf("%s: %d\n", "iabc--+- +1325632167", ft_atoi("iabc--+= +1325632167"));
	printf("%s: %d\n", " 2147483647", ft_atoi(" 2147483647"));
}
*/
