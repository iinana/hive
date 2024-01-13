/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:37:38 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 16:10:02 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int n)
{
	char	c;
	int		temp;

	temp = n / 16;
	if (temp > 9)
		c = temp + 55;
	else
		c = temp + '0';
	write(1, &c, 1);
	temp = n % 16;
	if (temp > 9)
		c = temp + 87;
	else
		c = temp + '0';
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	while (*str != 0)
	{
		if ((*str < 32) || (*str > 126))
		{
			i = (int)(*str);
			write(1, "\\", 1);
			print_hex(i);
		}
		else
			write(1, str, 1);
		str++;
	}
}

int	main(void) {
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
