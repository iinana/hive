/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:58:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/30 21:38:42 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_result	find_square(char **map, t_info info)
{
	t_result	res;

	res.size = info.x;
	if (res.size < info.y)
		res.size = info.y;
	res.x = 0;
	res.y = 0;
	if (recur_square(&res, map, info))
		return (res);
	res.size = -1;
	return (res);
}

int	recur_square(t_result *res, char **map, t_info info)
{
	int		obst_loc;

	if (res->size <= 0)
		return (0);
	if (res->x + res->size > info.x)
	{
		--(res->size);
		res->x = 0;
		res->y = 0;
		return (recur_square(res, map, info));
	}
	if (res->y + res->size > info.y)
	{
		++(res->x);
		res->y = 0;
		return (recur_square(res, map, info));
	}
	obst_loc = check_obst(res, map, info.obst);
	if (obst_loc >= 0)
	{
		res->y = obst_loc + 1;
		return (recur_square(res, map, info));
	}
	return (1);
}

int	check_obst(t_result *res, char **map, char obst)
{
	int		x;
	int		y;

	y = res->y + res->size;
	while (y > res->y)
	{
		y--;
		x = res->x + res->size;
		while (x > res->x)
		{
			x--;
			if (map[x][y] == obst)
				return (y);
		}
	}
	return (-1);
}
