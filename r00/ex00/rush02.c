/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:05:34 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 11:11:11 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(int character);

void	rush(int a, int b)
{
	int		x;
	int		y;

	y = 1;
	while (y <= b)
	{
		x = 1;
		while (x <= a)
		{
			if ((y == 1) && ((x == 1) || (x == a)))
				ft_putchar('A');
			else if ((y == b) && ((x == 1) || (x == a)))
				ft_putchar('C');
			else if ((x == 1) || (x == a) || (y == 1) || (y == b))
				ft_putchar('B');
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
