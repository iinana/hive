/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:46:42 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 18:47:48 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		find_num(char c, char *base);
char	*ft_itoa_base(long long int n, int bsize, char *base, int sign);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

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
