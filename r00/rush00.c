/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:51:57 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 10:33:00 by injung           ###   ########.fr       */
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
			if ((y == 1) || (y == b))
			{
				if ((x == 1) || (x == a))
					ft_putchar('o');
				else
					ft_putchar('-');
			}
			else if ((x == 1) || (x == a))
				ft_putchar('|');
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
