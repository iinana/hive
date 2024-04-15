/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:43 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 18:42:19 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*make_input(char **input)
{
	int		x;
	int		*res;

	res = (int *)malloc(32);
	x = 0;
	while (**input && (x < 8))
	{
		if ((**input >= '1') && (**input <= '4'))
		{
			res[x] = **input - '0';
			x++;
		}
		else if (**input != ' ')
		{
			res[0] = 0;
			return (res);
		}
		++(*input);
	}
	return (res);
}

int	check_col(int *res, int cur_col, int u, int d)
{
	int		x1;
	int		x2;
	int		max;
	int		count;

	x1 = 0;
	max = 0;
	count = 0;
	while (x1 < 4)
	{
		x2 = x1 + 1;
		while (x2 <= 4)
		{
			if (res[x1 * 4 + cur_col] == res[x2 * 4 + cur_col])
				return (0);
			x2++;
		}
		if (res[x1 * 4 + cur_col] > max)
		{
			max = res[x1 * 4 + cur_col];
			count++;
		}
		x1++;
	}
	if (count != u)
		return (0);
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

int check(int i, int cur_col, int cur_row, int *res, int l, int r)
{
	int		j;
	int		max;
	int		count;

	if (cur_col == 0)
		return (1);
	j = 0;
	max = 0;
	count = 0;
	while (j < cur_col)
	{
		if (i == res[cur_row * 4 + j])
			return (0);
		if (res[cur_row * 4 + j] > max)
		{
			max = res[cur_row * 4 + j];
			count++;
		}
		j++;
	}
	if (i > max)
		count++;
	if (count > l)
		return (0);
	max = i;
	count = 1;
	while (j > 0)
	{
		j--;
		if (res[cur_row * 4 + j] > max)
		{
			max = res[cur_row * 4 + j];
			count++;
		}
	}
	if (count > r)
		return (0);
	return (1);
}

int	put_row(int cur_col, int cur_row, int *row, int *col,  int **res)
{
	int		i;

	if ((cur_row == 3) && (cur_col >= 4))
	{
		i = 0;
		while (i < 4)
		{
			if (check_col(*res, i, col[i], col[i + 4]) == 0)
				return (0);
			i++;
		}
		return (1);
	}
	if (cur_col >= 4)
	{
		if (put_row(0, cur_row + 1, row, col, res))
			return (1);
		return (0);
	}
	i = 1;
	while (i <= 4)
	{
		if (check(i, cur_col, cur_row, *res, row[cur_row], row[cur_row + 4]))
		{
			(*res)[cur_row * 4 + cur_col] = i;
			if (put_row(cur_col + 1, cur_row, row, col, res))
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		**input;
	int		*res;
	int		i;
	char	c;
	
	input = (int **)malloc(64);
	res = (int *)malloc(64);
	if (argc != 2)
	{
		write(1, "1Error\n", 6);
		return (0);
	}	
	input[0] = make_input(argv + 1);
	input[1] = make_input(argv + 1);
	if (!(input[0][0] && input[1][0]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (put_row(0, 0, input[0], input[1], &res))
	{
		i = 0;
		while (i < 16)
		{
			c = res[i] + '0';
			write(1, &c, 1);
			if (i % 4 == 3)
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}


