/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/17 21:06:18 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(char *res, int idx, char i)
{
	char	pre;

	if (idx < 0)
		return (1);
	pre = res[idx];
	if ((i == pre) || (i == (pre - 1)) || (i == (pre + 1)))
		return (0);
	while (idx > 0)
	{
		idx--;
		pre = res[idx];
		if (i == pre)
			return (0);
	}
	return (1);
}	

void queens_puzzle(char *res, int idx, int *count)
{
	char	i;
 
	if (idx == 10)
		write(1, res, 12);
		++(*count);
		return ;
	}
	i = '0';
	while (i <= '9')
	{
		if (check(res, idx - 1, i) == 1)
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
	queens_puzzle(res, 0,  &count);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	printf("count = %d\n", ft_ten_queens_puzzle());
}
