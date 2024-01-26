/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:54:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 12:03:11 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/*
#include <stdio.h>
int is_lowcase(char *str)
{
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return ((int)(*str));
		str++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	printf("%d", ft_count_if(argv+1, argc-1, &is_lowcase));
}
*/
