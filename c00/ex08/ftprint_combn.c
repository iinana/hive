/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_combn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:35:48 by injung            #+#    #+#             */
/*   Updated: 2024/01/11 10:51:29 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_combn(int n)
{
	int		i;
	int		pow;
	int		j;
	char	res[10];
	int		count;

	i = 0;
	pow = 1;
	while (i < n)
		pow *= 10;
	i = 1;
	while (i < pow)
	{
		j = pow;
		count = 0
		while (count < n)
		{
			res[count] = (n 
}
