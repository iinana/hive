/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:41:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/23 16:33:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = (int *)malloc((max - min) * 4);
	if (!range)
		return (0);
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	int	min = 0;
	int	max = 0;
	int *ary;

	int size = ft_ultimate_range(&ary, min, max);
	if (ary == NULL)
		printf("NULL");
	for (int i = 0; i < size; i++)
		printf("%d ", ary[i]);
}
*/
