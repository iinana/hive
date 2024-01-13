/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:34:09 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 11:04:32 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(int character);

void	check(int a, int b, int x, int y)
{
	if ((x == 1) && (y == 1))
		ft_putchar('/');
	else if ((x == 1) && (y == b) && (b != 1))
		ft_putchar('\\');
	else if ((x == a) && (y == b) && (b != 1))
		ft_putchar('/');
	else if ((x == a) && (y == 1))
		ft_putchar('\\');
	else if ((x == 1) || (x == a) || (y == 1) || (y == b))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

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
			check(a, b, x, y);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
