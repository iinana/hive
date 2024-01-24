/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:53:04 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 11:31:33 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_int(int num)
{
	int		pow;
	char	c;

	pow = 1;
	while (num / pow >= 10)
		pow *= 10;
	while (pow > 0)
	{
		c = (num / pow) + '0';
		write(1, &c, 1);
		num = num % pow;
		pow /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		put_int(par->size);
		write(1, "\n", 1);
		write(1, par->copy, par->size);
		write(1, "\n", 1);
		par++;
	}
}

/*
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
int main(int argc, char **argv)
{
	t_stock_str *s = ft_strs_to_tab(argc, argv);
	ft_show_tab(s);
}
*/
