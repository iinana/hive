/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:58:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 19:44:48 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_result	find_square(char **map, t_info info)
{
	t_result	res;

	// Min(info.x, info.y)로 res.size 설정 (가능한 가능 큰 정사각형부터 탐색 시작)
	res.size = info.x;
	if (res.size < info.y)
		res.size = info.y;
	
	// 좌표 (0, 0)부터 탐색 시작
	res.x = 0;
	res.y = 0;

	// recur_square() 함수로 결과값을 찾으면 바로 리턴
	if (recur_square(&res, map, info))
		return (res);

	// 못 찾았다면 res.size를 0으로 하여 리턴
	res.size = 0;
	return (res);
}

int	recur_square(t_result *res, char **map, t_info info)
{
	int		obst_loc;

	// size가 0이라는 것은 가능한 정사각형 경우의 수를 모두 탐색했으나 결과 x이므로 바로 리턴
	if (res->size <= 0)
		return (0);
	// 해당 size로 가능한 경우가 없다면 size를 감소시키고 (0, 0)부터 재탐색 시작
	if (res->x + res->size > info.x)
	{
		--(res->size);
		res->x = 0;
		res->y = 0;
		return (recur_square(res, map, info));
	}
	// 가로로 이동하며 탐색을 완료했으면 한칸 아래로 내려가서 다시 탐색 시작
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

unsigned int	check_obst(t_result *res, char **map, char obst)
{
	unsigned int	x;
	unsigned int	y;

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
