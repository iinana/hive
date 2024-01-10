/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:40:44 by injung            #+#    #+#             */
/*   Updated: 2024/01/10 21:51:44 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	res[5];
	int		temp;
	int		a;
	int		b;

	res[2] = ' ';
	a = 0;
	while (a < 99)
	{
		temp = a / 10;
		res[0] = temp + 48;
		res[1] = (a - temp * 10) + 48;
		b = a + 1;
		while (b < 100)
		{
			temp = b / 10;
			res[3] = temp + 48;
			res[4] = (b - temp * 10) + 48;
			write(1, res, 5);
			if (!((a == 98) && (b == 99)))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
