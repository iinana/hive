/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:16:10 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 10:05:15 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int		i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

/*
#include <stdio.h>
#include <stdlib.h>
void	put_nbr(int n)
{
	printf("%d\n", n);
}
int	main(void)
{
	int *ary = (int *)malloc(sizeof(int) * 10);
	for (int i = -3; i < 4; i++)
		ary[i + 3] = i;
	ft_foreach(ary, 6, &put_nbr);
}
*/
