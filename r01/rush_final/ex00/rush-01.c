/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:43 by injung            #+#    #+#             */
/*   Updated: 2024/01/22 13:57:11 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*make_input(char **input);
int		put_row(int cur_col, int cur_row, int **input, int **res);
void	print_res(int wid, int hei, int *res);
int		check_row_dup(int i, int cur_col, int cur_row, int *res);
int		check_rowl(int cur_col, int cur_row, int *res, int l);
int		check_rowr(int cur_row, int *res, int r);
int		check_col_dup(int *res, int cur_col);
int		check_colu(int *res, int cur_col, int u);
int		check_cold(int *res, int cur_col, int d);
int		check_col(int *res, int cur_col, int u, int d);
int		check_multi_col(int *res, int *col);

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

int	put_row(int cur_col, int cur_row, int **input, int **res)
{
	int		i;
	int		j;

	if ((cur_row == 3) && (cur_col >= 4))
	{
		if (check_multi_col(*res, input[0]) == 0)
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
	free(input[0]);
	free(input[1]);
	free(input);
	free(res);
}
