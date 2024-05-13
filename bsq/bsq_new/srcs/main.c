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

	if (argc == 1)	// parameter로 파일명을 안받은 경우 = map을 터미널 입력으로
		map = make_std_map(&info);
	else if (argc == 2)  // parameter로 파일명을 받은 경우
		map = make_file_map(argv[1], &info);
	else
	{
		ft_putstr("map error\n");
		exit(1);
	}

	if (map == NULL)  // map 만드는 데에 실패한 경우
	{
		ft_putstr("map error\n");
		exit(1);
	}

	// 결과값 찾기
	res = find_square(map, info);
	printf("find square complete: x=%d, y=%d, size=%d\n", res.x, res.y, res.size);
	if (res.size == 0)	// 결과값 찾기에 실패한 경우는 map 자체 출력
		print_map(map, info);
	else	// 결과 찾기에 성공했다면 결과 출력
		print_res(res, map, info);
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

	printf("x:%d, y:%d, size:%d | %c\n", res.x, res.y, res.size, info.full);
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
