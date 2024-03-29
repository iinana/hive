/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:12:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 13:32:14 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	return_hex(int n)
{
	if (n <= 9)
		return (n + '0');
	else
		return (n + 87);
}

void	print_address(unsigned long long int add)
{
	long long unsigned int		pow;
	int							count;
	char						c;

	pow = 1;
	count = 0;
	while (count < 15)
	{
		pow *= 16;
		count++;
	}
	while (pow > 0)
	{
		c = return_hex(add / pow);
		write(1, &c, 1);
		add = add % pow;
		pow /= 16;
	}
}

void	print_ascii(unsigned char *str, int len)
{
	int				i;
	int				num;
	unsigned char	c;

	i = 0;
	while (i < len)
	{
		num = (unsigned int)str[i];
		c = return_hex(num / 16);
		write(1, &c, 1);
		c = return_hex(num % 16);
		write(1, &c, 1);
		if ((i % 2) == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if ((i % 2) == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_char(unsigned char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if ((str[i] < 32) || (str[i] > 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned int	i;
	unsigned int	n;

	if (size == 0)
		return (addr);
	str = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if ((size - i) >= 16)
			n = 16;
		else
			n = size - i;
		print_address((unsigned long long)str[i]);
		write(1, ": ", 2);
		print_ascii(&str[i], n);
		write(1, " ", 1);
		print_char(&str[i], n);
		write(1, "\n", 1);
		i += n;
	}
	return (addr);
}
