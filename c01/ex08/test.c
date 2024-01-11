/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:48:47 by injung            #+#    #+#             */
/*   Updated: 2024/01/11 17:07:46 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *num1, int *num2)
{
	int		temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int	check_condition(int high, int low, int *nums)
{
	if (high <= low)
		return (1);
	else if ((high - low) == 1)
	{
		if (nums[low] > nums[high])
			swap(&nums[low], &nums[high]);
		return (1);
	}
	return (0);
}

void	quick_sort(int *nums, int low, int high)
{
	int		pivot;
	int		inith;

	if (check_condition(high, low, nums) == 1)
		return;
	pivot = low++;
	inith = high;
	while (low < high)
	{
		while ((nums[low] <= nums[pivot]) && (low <= high))
			low++;
		while ((nums[high] >= nums[pivot]) && (low <= high))
			high--;
		if (low >= high)
			break ;
		swap(&nums[low], &nums[high]);
		low++;
		high--;
	}
	swap(&nums[high], &nums[pivot]);
	quick_sort(nums, pivot, high - 1);
	quick_sort(nums, high + 1, inith);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size - 1);
}

int main() {
	int nums[10] = { 3, 930, 39, -38, 0, 2, 2 };
	ft_sort_int_tab(nums, 7);
	for (int i = 0; i < 7; i++) printf("%d ", nums[i]);
}
