/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:32:34 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 19:12:06 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**make_std_map(t_info *info)
{
	// map 만들기 전 기본 정보 채우기에 실패하면 0 리턴
	if (fill_std_info(info) == 0)
		return (NULL);
	if (info->x == 0)
		return (NULL);

	// fill_map() 함수로 만든 map 바로 리턴
	return (fill_map(info, 1));
}

int	fill_std_info(t_info *info)
{
	char	c;
	char	signs[3];
	int		i;

	// 숫자에 해당 하는 부분을 int type으로 변환하여 row 정보 입력
	info->x = 0;
	while (read(0, &c, 1) > 0 && c >= '0' && c <= '9')
		info->x = (info->x) * 10 + c - '0';

	// 나머지 문자는 sign 배열에 하나씩 저장
	signs[0] = c;
	i = 1;
	while (i < 3 && c != '\n' && read(0, &c, 1) >= 0)
		signs[i++] = c;

	// 만약 sign 배열이 다 채워졌는데, 
	// 다음 문자가 존재하지 않거나, 한 문장이 끝나지 않은 경우 0 리턴
	if (i == 3 && (read(0, &c, 1) < 0 || c != '\n'))
		return (0);

	// 앞서 입력 받은 정보들로 info 구조체 채우기
	set_info(info, i, signs);

	// map이 존재할 수 없는 상황(row가 0)이거나 
	// obstacle, full, empty 문자 중 같은 문자가 있다면 0 리턴
	if (info->x == 0 || info->obst == info->full)
		return (0);
	if (info->empt == info->obst || info->empt == info->full)
		return (0);
	return (1);
}

void	set_info(t_info *info, int i, char signs[3])
{
	if (i == 3)	// 문자 세개 다 채워진 채로 온 경우
		set_chars(info, signs[0], signs[1], signs[2]);
	else if (i == 2) // 문자가 두개만 채워진 경우 -> x로 넣었던 마지막 숫자가 사실 empty문자
	{
		set_chars(info, ((info->x) % 10 + '0'), signs[0], signs[1]);
		(info->x) /= 10;
	}
	else if (i == 1) // 문자가 하나만 채워진 경우 -> x로 넣었던 마지막 두 개 숫자가 사실 empty와 obstable 문자
	{
		set_chars(info, 0, ((info->x) % 10 + '0'), signs[0]);
		(info->x) /= 10;
		info->empt = (info->x) % 10 + '0';
		(info->x) /= 10;
	}
	else  // 문자가 하나도 채워지지 않은 경우 -> x로 넣었던 마지막 숫자 세개가 사실 empty, obstabcle, full 문자
	{
		info->full = (info->x) % 10 + '0';
		(info->x) /= 10;
		info->obst = (info->x) % 10 + '0';
		(info->x) /= 10;
		info->empt = (info->x) % 10 + '0';
		(info->x) /= 10;
	}
}

char	**fill_map(t_info *info, unsigned int x)
{
	char	**map;

	// row만큼 메모리 할당
	map = (char **)malloc(sizeof(char *) * (info->x));
	if (map == NULL)
		return (NULL);

	// 첫번째 row 입력받으면서 colum 수 파악
	info->y = make_first_line(info, &(map[0]), 0);
	if (info->y == 0)
	{
		free(map);
		return (NULL);
	}

	// row 하나씩 채우기
	while (x < info->x)
	{
		printf("x=%d\n", x);
		map[x] = map_array(0, x, info);
		if (map[x] == NULL)
		{
			while (x > 0)
				free(map[--x]);
			free(map);
			return (NULL);
		}
		x++;
	}
	return (map);
}

// std 입력에서 첫 번째 줄의 길이를 알아내기 위해 첫번째줄만 따로 입력받는 함수
// 첫번째 줄의 크기에 맞을 때까지 재귀를 통해 배열의 크기를 10씩 늘려가면서 입력받는다
unsigned int	make_first_line(t_info *info, char **line, unsigned int size)
{
	char			c;
	char			*res;
	unsigned int	i;

	// res 배열에 size + 10의 메모리를 할당
	res = (char *)malloc(sizeof(char) * (size + 10));
	if (res == NULL)
		return (0);

	// 현재까지 line 배열에 입력되어있는 문자들을 res 배열로 옮김
	if (size > 0)
	{
		ft_strncpy(res, *line, size);
		free(*line);
	}

	i = size;
	while (i < (size + 10))
	{
		if (read(0, &c, 1) < 0 || c == '\n') {
			*line = res;
			return (i);
		}
		if (!is_allowed(c, info))
			return (0);
		res[i++] = c;
	}

	// 기존 line 배열을 size가 10 커진 res배열로 대체
	*line = res;

	// size를 증가시켜 재귀
	return (make_first_line(info, line, size + 10));
}
