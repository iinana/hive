/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/18 10:36:48 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *res, int idx, char cur)
{
	char	pre;
	int		j;

	if (idx < 0)
		return (1);
	j = 0;
	while (j < idx)
	{
		pre = res[j];
		if (cur == pre)
			return (0);
		if ((cur - pre) == (idx - j))
			return (0);
		if ((cur - pre) == (j - idx))
			return (0);
		j++;
	}
	return (1);
}

void	queens_puzzle(char *res, int idx, int *count)
{
	char	i;

	if (idx == 10)
	{
		write(1, res, 12);
		++(*count);
		return ;
	}
	i = '0';
	while (i <= '9')
	{
		if (check(res, idx, i) == 1)
		{
			res[idx] = i;
			queens_puzzle(res, idx + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	res[12];

	res[10] = '\n';
	res[11] = 0;
	count = 0;
	queens_puzzle(res, 0, &count);
	return (count);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("count = %d\n", ft_ten_queens_puzzle());
}
*/
