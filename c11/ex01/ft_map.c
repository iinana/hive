/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:06:01 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 11:20:10 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * length);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(tab[i]);
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
int	add(int a)
{
	return (a + 10);
}
int main(void)
{
	int *ary = (int *)malloc(sizeof(int) * 10);
	for (int i = -4; i < 3; i++)
		ary[i+4] = i;
	int *ary2 = ft_map(ary, 7, &add);
	for (int i = 0; i < 7; i++)
		printf("%d ", ary2[i]);
}
*/
