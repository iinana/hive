/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:24:13 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 15:30:24 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	make_dict(char *path, dictionary *dict)
{
	char	c;
	char	num[10];
	int		i;
	int		infile;
	int		max_size;

	infile = open(path, O_RDONLY);
	max_size = count_max(path) + 1;
	i = 0;
	while (read(infile, &c, 1) > 0)
	{
		if (c == '\n')
			i = 0;
		else if (c >= '0' && c <= '9')
		{
			num[i++] = c;
			while (i < 3 && read(infile, &c, 1) > 0 && c >= '0' && c <= '9')
				num[i++] = c;
			if (i >= 3)
			{
				num[i] = 0;
				if (!make_dict_digit(infile, max_size, num, &(dict->digit)))
				{
					while (read(infile, &c, 1) > 0 && c != '\n')
						continue ;
				}
			}
			else
			{
				while (c == ' ' && read(infile, &c, 1) > 0)
					continue ;
				if (c == ':')
				{
					num[i] = 0;
					if (!make_dict_num(infile, max_size, num, &(dict->num)))
					{
						while (read(infile, &c, 1) > 0 && c != '\n')
							continue ;
					}
				}
				else
				{
					while (c != '\n' && read(infile, &c, 1) > 0)
						continue ;
				}
			}
			i = 0;
		}
	}
	close(infile);
	return (1);
}

int	make_dict_num(int infile, int max_size, char num[10], char ***dict)
{
	char	c;
	int		key;

	if (!num[1])
		key = num[0] - '0';
	else
		key = (num[0] - '0') * 10 + num[1] - '0';
	(*dict)[key] = make_value(infile, max_size);
	if ((*dict)[key] == NULL)
		return (0);
	return (1);
}

int	make_dict_digit(int infile, int max_size, char num[10], char ***dict)
{
	char	c;
	int		key;

	if (num[0] == '1')
		key = 1;
	else
		return (0);
	while (num[key])
	{
		if (num[key] != '0')
			return (0);
		key++;
	}
	while (read(infile, &c, 1) > 0 && c == ' ')
		continue ;
	while (c == '0' && read(infile, &c, 1) > 0)
		key++;
	while (c == ' ' && read(infile, &c, 1) > 0)
		continue ;
	if (c != ':')
		return (0);
	(*dict)[key] = make_value(infile, max_size);
	if ((*dict)[key] == NULL)
		return (0);
	return (1);
}

char	*make_value(int infile, int max_size)
{
	char			*value;
	unsigned char	c;
	int				i;

	value = (char *)malloc(sizeof(char) * max_size);
	while (read(infile, &c, 1) > 0 && c == ' ')
		continue ;
	i = 0;
	if (is_printable(c))
	{
		value[i] = c;
		i++;
	}
	else
		return (NULL);
	while (read(infile, &c, 1) > 0  && c != '\n')
	{
		if (!is_printable(c))
			return (NULL);
		value[i] = c;
		i++;
	}
	value[i] = 0;
	return (value);
}

int	count_max(char *path)
{
	int		infile;
	char	c;
	int		count;
	int		max;

	infile = open(path, O_RDONLY);
	max = 0;
	while (read(infile, &c, 1) > 0)
	{
		if (c == ':')
		{
			count = 0;
			while (read(infile, &c, 1) > 0 && c != '\n' && c == ' ')
				continue ;
			while (read(infile, &c, 1) > 0 && c != '\n' && c != ' ')
				count++;
			if (count > max)
				max = count;
		}
	}
	close(infile);
	return (max);
}
