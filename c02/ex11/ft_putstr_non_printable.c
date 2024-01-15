/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:37:38 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 20:24:27 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	return_hex(char n)
{
	if (n <= 9)
		return (n + '0');
	else
		return (n + 87);
}

void	ft_putstr_non_printable(char *str)
{
	char			c;
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (*temp != 0)
	{
		if ((*temp < 32) || (*temp > 126))
		{
			write(1, "\\", 1);
			c = return_hex(*temp / 16);
			write(1, &c, 1);
			c = return_hex(*temp % 16);
			write(1, &c, 1);
		}
		else
			write(1, temp, 1);
		temp++;
	}
}
