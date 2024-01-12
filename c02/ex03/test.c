/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:03:04 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 13:08:12 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if ((str[idx] < '0') || (str[idx] > '9'))
			return (0);
		idx++;
	}
	return (1);
}

int main(void)
{
	printf("%d %d", ft_str_is_numeric("128320112"), ft_str_is_numeric("dfajl32502934"));
}
