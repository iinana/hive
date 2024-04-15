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

char	**fill_map(t_info *info, unsigned int x)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (info->x));
	if (map == NULL)
		return (NULL);
	info->y = make_first_line(info, &(map[0]), 0);
	if (info->y == 0)
	{
		free(map);
		return (NULL);
	}
	while (x < info->x)
	{
		map[x] = map_array(0, info);
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

int	fill_std_info(t_info *info)
{
	char	c;
	char	signs[4];
	int		i;

	info->x = 0;
	while (read(0, &c, 1) > 0 && c >= '0' && c <= '9')
		info->x = (info->x) * 10 + c - '0';
	signs[0] = c;
	i = 1;
	while (i < 3 && c != '\n' && read(0, &c, 1) >= 0)
		signs[i++] = c;
	signs[i] = 0;
	if (i == 3 && (read(0, &c, 1) < 0 || c != '\n'))
		return (0);
	if (c != '\n')
		return (0);
	set_info(info, i, signs);
	if (info->x == 0 || info->obst == info->full)
		return (0);
	if (info->empt == info->obst || info->empt == info->full)
		return (0);
	return (1);
}

void	set_info(t_info *info, int i, char signs[4])
{
	if (i == 3)
		set_chars(info, signs[0], signs[1], signs[2]);
	else if (i == 2)
	{
		set_chars(info, ((info->x) % 10 + '0'), signs[0], signs[1]);
		(info->x) /= 10;
	}
	else if (i == 1)
	{
		set_chars(info, 0, ((info->x) % 10 + '0'), signs[0]);
		(info->x) /= 10;
		info->empt = (info->x) % 10 + '0';
		(info->x) /= 10;
	}
	else
	{
		info->full = (info->x) % 10 + '0';
		(info->x) /= 10;
		info->obst = (info->x) % 10 + '0';
		(info->x) /= 10;
		info->empt = (info->x) % 10 + '0';
		(info->x) /= 10;
	}
}

void	set_chars(t_info *info, char e, char o, char f)
{
	info->empt = e;
	info->obst = o;
	info->full = f;
}

unsigned int	make_first_line(t_info *info, char **line, unsigned int size)
{
	char	c;
	char	*res;

	if (read(0, &c, 1) < 0 || c == '\n')
		return (size);
	if (!is_allowed(c, info))
		return (0);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (0);
	if (size > 0)
	{
		ft_strncpy(res, *line, size);
		free(*line);
	}
	res[size] = c;
	*line = res;
	return (make_first_line(info, line, size + 1));
}
