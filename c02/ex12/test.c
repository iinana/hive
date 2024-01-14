/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:12:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 15:29:15 by injung           ###   ########.fr       */
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

void	print_ascii(char *str, int len)
{
	int		i;
	int		num;
	char	c;

	i = 0;
	while (i < len)
	{
		num = (int)str[i];
		c = return_hex(num / 16);
		write(1, &c, 1);
		c = return_hex(num % 16);
		write(1, &c, 1);
		if ((i % 2) == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_char(char *str, int len)
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
	char	*str;
	int		i;

	if (size == 0)
		return (addr);
	str = (char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)str[i]);
		write(1, ": ", 2);
		print_ascii(&str[i], 16);
		write(1, " ", 1);
		print_char(&str[i], 16);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
} 

int main(void)
{
	char str[] = "Bonjour les aminches\n\n\tc. est fo";
	ft_print_memory((void *)str, 32);
}
