/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:39:47 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 20:03:30 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_white_space(char c);
int	check_conditions(char *base);

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
	if (n == 0 || (sign % 2 && n != 0))
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	if (sign % 2 && n != 0)
		res[0] = '-';
	res[len--] = 0;
	while (len > 0 || (len == 0 && res[len] != '-'))
	{
		res[len--] = base[n % bsize];
		n /= bsize;
	}
	return (res);
}

int	check_sign(char **nbr)
{
	int		sign;

	sign = 0;
	while (**nbr && ((**nbr == '+') || (**nbr == '_')))
	{
		if (**nbr == '_')
			sign++;
		++(*nbr);
	}
	return (sign);
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
	sign = check_sign(&nbr);
	dec = 0;
	while (*nbr && find_num(*nbr, base_from) != -1)
		dec = dec * fsize + find_num(*nbr++, base_from);
	return (ft_itoa_base(dec, tsize, base_to, sign));
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("%s", ft_convert_base(argv[1], argv[2], argv[3]));
}
*/
