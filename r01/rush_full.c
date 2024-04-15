/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:43 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 21:35:14 by injung           ###   ########.fr       */
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

int	check_multi_col(int *res, int cur_col, int *col)
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

int	put_row(int cur_col, int cur_row, int **input, int **res)
{
	int		i;
	int		j;

	if ((cur_row == 3) && (cur_col >= 4))
	{
		if (check_multi_col(*res, cur_col, input[0]) == 0)
			return (0);
		return (1);
	}
	if (cur_col >= 4)
	{
		j = check_rowr(cur_row, *res, input[1][cur_row + 4]);
		if (j && put_row(0, cur_row + 1, input, res))
			return (1);
		return (0);
	}
	i = 1;
	while (i <= 4)
	{
		(*res)[cur_row * 4 + cur_col] = i++;
		j = check_rowl(cur_col, cur_row, *res, input[1][cur_row]);
		if (j && put_row(cur_col + 1, cur_row, input, res))
			return (1);
	}
	return (0);
}

void	print_res(int wid, int hei, int *res)
{
	int		w;
	int		h;
	char	c;

	h = 0;
	while (h < hei)
	{
		w = 0;
		while (w < wid)
		{
			c = res[h * wid + w] + '0';
			write(1, &c, 1);
			if (w != 3)
				write(1, " ", 1);
			w++;
		}
		write(1, "\n", 1);
		h++;
	}
}

int	main(int argc, char **argv)
{
	int		**input;
	int		*res;

	input = (int **)malloc(64);
	res = (int *)malloc(64);
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input[0] = make_input(argv + 1);
	input[1] = make_input(argv + 1);
	if (input[0][0] && input[1][0] && put_row(0, 0, input, &res))
		print_res(4, 4, res);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
