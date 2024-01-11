/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:11:46 by injung            #+#    #+#             */
/*   Updated: 2024/01/11 13:44:46 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		start;
	int		end;
	int		temp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

int main() {
	int nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("nums[0] = %d\n", nums[0]);
	ft_rev_int_tab(nums, 10);
	for (int i = 0; i < 10; i++) printf("%d ", nums[i]);
	printf("\n");

	ft_rev_int_tab(nums, 9);
	for (int i = 0; i < 9; i++) printf("%d ", nums[i]);
}
