/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:12:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 20:47:29 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 문자열을 16자씩 나누어서 출력하는데,
3개의 칼럼으로 나눠서
메모리주소 | 아스키코드 | 해당문자
출력하고 각각은 스페이스로 구분하고, 아스키코드는 두 개 출력 후 스페이스 출력 반복, nonprintable문자는 마침표(.)로 표시... */

#include <unistd.h>

char	return_hex(int n)
{
	char	hex[17];

	hex = "0123456789abcdef";
	return (hex[n]);
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



	
void	print_char();

void	*ft_print_memeory(void *addr, unsigned int size)
{
	char	*str;
	int		i;

	if (size == 0)
		return ;
	str = (char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)str);
		write(1, ": ", 2);
		print_ascii(str, size - i);
		write(1, " ", 1);
		print_char(str[1]);
		write(1, "\n", 1);
	}
}
