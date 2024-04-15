/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:49:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 21:54:52 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*make_input(char **input);
int		put_row(int cur_col, int cur_row, int **input, int **res);
void	print_res(int wid, int hei, int *res);
int		check_col_dup(int *res, int cur_col);
int		check_colu(int *res, int cur_col, int u);
int		check_cold(int *res, int cur_col, int d);
int		check_col(int *res, int cur_col, int u, int d);
int		check_multi_col(int *res, int *col);

int	check_col_dup(int *res, int cur_col)
{
	int		x1;
	int		x2;

	x1 = 0;
	while (x1 < 4)
	{
		x2 = x1 + 1;
		while (x2 <= 4)
		{
			if (res[x1 * 4 + cur_col] == res[x2 * 4 + cur_col])
				return (0);
			x2++;
		}
		x1++;
	}
	return (1);
}

int	check_colu(int *res, int cur_col, int u)
{
	int		x1;
	int		max;
	int		count;

	x1 = 0;
	max = 0;
	count = 0;
	while (x1 < 4)
	{
		if (res[x1 * 4 + cur_col] > max)
		{
			max = res[x1 * 4 + cur_col];
			count++;
		}
		x1++;
	}
	if (count != u)
		return (0);
	return (1);
}

int	check_cold(int *res, int cur_col, int d)
{
	int		x1;
	int		max;
	int		count;

	x1 = 4;
	max = 0;
	count = 0;
	while (x1 > 0)
	{
		x1--;
		if (res[x1 * 4 + cur_col] > max)
		{
			max = res[x1 * 4 + cur_col];
			count++;
		}
	}
	if (count != d)
		return (0);
	return (1);
}

int	check_col(int *res, int cur_col, int u, int d)
{
	if (!check_col_dup(res, cur_col))
		return (0);
	if (!check_colu(res, cur_col, u))
		return (0);
	if (!check_cold(res, cur_col, d))
		return (0);
	return (1);
}

int	check_multi_col(int *res, int *col)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (check_col(res, i, col[i], col[i + 4]) == 0)
			return (0);
		i++;
	}
	return (1);
}
