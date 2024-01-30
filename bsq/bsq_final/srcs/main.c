/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/30 21:42:57 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_info		info;
	char		**map;
	t_result	res;

	if (argc != 2)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	map = make_map(argv[1], &info);
	if (map == NULL)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	res = find_square(map, info);
	if (res.size == -1)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	print_res(res, map, info);
}

void	print_res(t_result res, char **map, t_info info)
{
	int		x;
	int		y;

	x = 0;
	while (x < info.x)
	{
		y = 0;
		while (y < info.y)
		{
			if (x >= res.x && x < (res.x + res.size))
			{
				if (y >= res.y && y < (res.y + res.size))
				{
					write(1, &(info.full), 1);
					y++;
					continue ;
				}
			}
			write(1, &(map[x][y]), 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}
