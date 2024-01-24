/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:39:47 by injung            #+#    #+#             */
/*   Updated: 2024/01/23 16:42:37 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_itoa_base(long long int n, int bsize, char *base, int sign)
{
	int					len;
	char				*res;
	long long int		temp;

	len = 0;
	temp = n;
	while (temp > 0)
	{
		len++;
		temp /= bsize;
	}
	if (sign % 2)
	{
		res = (char *)malloc(++len + 1);
		res[0] = '-';
	}
	else
		res = (char *)malloc(len + 1);
	res[len--] = 0;
	while (len > 0 || (len == 0 && res[len] != '-'))
	{
		res[len--] = base[n % bsize];
		n /= bsize;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int		fsize;
	int					tsize;
	int					sign;
	long long int		dec;

	fsize = check_conditions(base_from);
	tsize = check_conditions(base_to);
	if ((fsize <= 1) || (tsize <= 1))
		return (0);
	while (*nbr && is_white_space(*nbr))
		nbr++;
	sign = 0;
	while (*nbr && ((*nbr == '+') || (*nbr == '-')))
	{
		if (*nbr == '-')
			sign++;
		nbr++;
	}
	dec = 0;
	while (*nbr && find_num(*nbr, base_from) != -1)
		dec = dec * fsize + find_num(*nbr++, base_from);
	if (dec == 0)
		return ("0");
	return (ft_itoa_base(dec, tsize, base_to, sign));
}

/*
#include <stdio.h>
int main(void)
{
	char nbr[20] = "101010";
	char base_from[30] = "01";
	char base_to[30] = "0123456789ABCDEF";

	printf("%s", ft_convert_base(nbr, base_from, base_to));
}
*/
