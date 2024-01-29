/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:15:58 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 13:24:51 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1] == 0))
			return (0);
		i++;
	}
	return (1);
}

/*
int	compare(int a, int b)
{
	if (a < b)
		return (-1);
	else
		return (0);
}

#include <stdio.h>
int main()
{
	int ary1[] = {1, 2, 3, 4, 5, 6};
	int ary2[] = {-1, 2, 3, 0};
	printf("ary1: %d\n", ft_is_sort(ary1, 6, &compare));
	printf("ary2: %d\n", ft_is_sort(ary2, 4, &compare));
}
*/
