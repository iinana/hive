/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_combn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:25:10 by injung            #+#    #+#             */
/*   Updated: 2024/01/18 15:45:55 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur_comb(int cur, int end, char *res)
{
	int		i;

	if (cur > end)
	{
		write(1, res, 11);
		return ;
	}
	if (cur == 0)
		i = '0';
	else
		i = res[cur - 1] + 1;
	while (i <= '9')
	{
		res[cur] = i;
		recur_comb(cur + 1, end, res);
		i++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	res[11];

	if ((n <= 0) || (n >= 10))
		return ;
	res[9] = ' ';
	res[10] = 0;
	recur_comb(0, n - 1, res);
}

int main()
{
	ft_print_combn(2);
}
