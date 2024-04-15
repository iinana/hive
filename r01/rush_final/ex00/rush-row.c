/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:50:08 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 21:54:24 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*make_input(char **input);
int		put_row(int cur_col, int cur_row, int **input, int **res);
void	print_res(int wid, int hei, int *res);
int		check_row_dup(int i, int cur_col, int cur_row, int *res);
int		check_rowl(int cur_col, int cur_row, int *res, int l);
int		check_rowr(int cur_row, int *res, int r);

int	check_row_dup(int i, int cur_col, int cur_row, int *res)
{
	int		j;

	j = 0;
	while (j < cur_col)
	{
		if (i == res[cur_row * 4 + j])
			return (0);
		j++;
	}
	return (1);
}

int	check_rowl(int cur_col, int cur_row, int *res, int l)
{
	int		j;
	int		max;
	int		count;

	if (cur_col == 0)
		return (1);
	if (!check_row_dup(res[cur_row * 4 + cur_col], cur_col, cur_row, res))
		return (0);
	j = 0;
	max = 0;
	count = 0;
	while (j < cur_col)
	{
		if (res[cur_row * 4 + j] > max)
		{
			max = res[cur_row * 4 + j];
			count++;
		}
		j++;
	}
	if (res[cur_row * 4 + cur_col] > max)
		count++;
	if (count > l)
		return (0);
	return (1);
}

int	check_rowr(int cur_row, int *res, int r)
{
	int		i;
	int		max;
	int		count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (res[cur_row * 4 + i] > max)
		{
			max = res[cur_row * 4 + i];
			count++;
		}
		i--;
	}
	if (count != r)
		return (0);
	return (1);
}
