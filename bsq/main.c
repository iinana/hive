/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 19:12:20 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_info		info;
	char		**map;
	t_result	res;

	if (argc == 1)
		map = make_std_map(&info);
	else if (argc == 2)
		map = make_file_map(argv[1], &info);
	else
	{
		ft_putstr("map error\n");
		exit(1);
	}
	if (map == NULL)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	res = find_square(map, info);
	if (res.size == 0)
		print_map(map, info);
	else
		print_res(res, map, info);
}

char	**make_std_map(t_info *info)
{
	if (info == NULL)
		return (NULL);
	if (fill_std_info(info) == 0)
		return (NULL);
	if (info->x == 0)
		return (NULL);
	return (fill_map(info, 1));
}

void	print_map(char **map, t_info info)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < info.x)
	{
		y = 0;
		while (y < info.y)
		{
			write(1, &(map[x][y]), 1);
			y++;
		}
		x++;
		write(1, "\n", 1);
	}
}

void	print_res(t_result res, char **map, t_info info)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < info.x)
	{ y = 0;
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
