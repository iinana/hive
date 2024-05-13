/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:53:03 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 19:12:40 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**make_file_map(char *path, t_info *info)
{
	char			**map;
	int				infile;
	unsigned int	x;

	// 기본 정보 채우기에 실패할 경우 NULL 리턴 (잘못된 입력)
	if (fill_file_info(path, info) == 0)
		return (NULL);

	// empty, obstacle, full 문자들 간 중복 존재할 경우 NULL 리턴 (잘못된 입력)
	if (info->empt == info->obst || info->empt == info->full)
		return (NULL);
	if (info->obst == info->full)
		return (NULL);

	// 파일 열고 메모리 할당
	infile = open(path, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * info->x);
	if (infile < 0 || map == NULL)
		return (NULL);

	// count_line() 함수 이용해서 단순히 이미 info 파악 위해 읽었던 첫 줄 skip
	count_line(infile);

	// 한 줄씩 map 채우기
	x = 0;
	while (x < info->x)
	{
		map[x] = map_array(infile, x, info);
		if (map[x] == NULL)
			return (NULL);
		x++;
	}
	return (map);
}

// 기본적인 map에 대한 정보를 담은 info 구조체 채우기
// 여기서 한 번 파일을 읽고 map을 읽어들일 때는 파일을 다시 연다.
int	fill_file_info(char *path, t_info *info)
{
	int				infile;
	char			c;
	char			*info_line;
	unsigned int	len;

	// 파일을 열어서 첫번째 줄의 길이를 센다
	infile = open(path, O_RDONLY);
	if (infile < 0)
		return (0);
	len = count_line(infile);

	// 첫번째 줄의 길이만큼 할당한 배열을 만든다
	info_line = (char *)malloc(sizeof(char) * (len + 1));
	
	// 파일을 다시 열어 만든 배열에 첫번째 줄을 복사해 넣는다
	infile = open(path, O_RDONLY);
	if (infile < 0)
		return (0);
	len = 0;
	while (read(infile, &c, 1) > 0 && c != '\n')
		info_line[len++] = c;

	// info를 채워넣는다
	set_chars(info, info_line[len-3], info_line[len-2], info_line[len-1]);
	info->x = ft_atoi(info_line, len-3);

	// y는 다시 다음 줄의 길이를 세서 넣음
	info->y = count_line(infile);
	close(infile);

	if (info->x == 0 || info->y == 0)
		return (0);
	return (1);
}