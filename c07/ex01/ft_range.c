/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:31:09 by injung            #+#    #+#             */
/*   Updated: 2024/01/23 16:33:31 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ary;
	int	i;

	if (min >= max)
		return (0);
	ary = (int *)malloc((max - min) * 4);
	if (!ary)
		return (0);
	i = 0;
	while (min < max)
	{
		ary[i] = min;
		i++;
		min++;
	}
	return (ary);
}

/*
#include <stdio.h>
int	main(void)
{
	int	min = 4;
	int	max = 9;
	int *ary = ft_range(min, max);

	if (ary == NULL)
		printf("NULL");
	for (int i = 0; i < (max - min); i++)
		printf("%d ", ary[i]);
}
*/
