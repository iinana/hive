/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:53:03 by injung            #+#    #+#             */
/*   Updated: 2024/01/30 21:48:22 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**make_map(char *path, t_info *info)
{
	char		**map;
	int			infile;
	int			x;

	if (fill_info(path, info) == 0)
		return (NULL);
	if (info->empt == info->obst || info->empt == info->full)
		return (NULL);
	if (info->obst == info->full)
		return (NULL);
	infile = open(path, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * info->x);
	if (infile < 0 || map == NULL)
		return (NULL);
	count_line(infile);
	x = 0;
	while (x < info->x)
	{
		map[x] = map_array(infile, info);
		if (map[x] == NULL)
			return (NULL);
		x++;
	}
	return (map);
}

int	fill_info(char *path, t_info *info)
{
	int		infile;
	char	c;
	char	*info_line;
	int		len;

	infile = open(path, O_RDONLY);
	if (infile < 0)
		return (0);
	len = count_line(infile);
	info_line = (char *)malloc(sizeof(char) * (len + 1));
	infile = open(path, O_RDONLY);
	if (infile < 0)
		return (0);
	len = 0;
	while (read(infile, &c, 1) > 0 && c != '\n')
		info_line[len++] = c;
	info->full = info_line[--len];
	info->obst = info_line[--len];
	info->empt = info_line[--len];
	info->x = ft_atoi(info_line, len);
	info->y = count_line(infile);
	if (info->x == 0 || info->y == 0)
		return (0);
	return (1);
}

char	*map_array(int infile, t_info *info)
{
	char	*array;
	char	c;
	int		y;

	array = (char *)malloc(sizeof(char) * (info->y));
	if (array == NULL)
		return (NULL);
	y = 0;
	while (y < info->y)
	{
		if (read(infile, &c, 1) < 0 || !is_allowed(c, info))
			return (NULL);
		array[y] = c;
		y++;
	}
	if (read(infile, &c, 1) < 0 || c != '\n')
		return (NULL);
	return (array);
}

int	is_allowed(char c, t_info *info)
{
	if (c != info->empt && c != info->obst && c != info->full)
		return (0);
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
