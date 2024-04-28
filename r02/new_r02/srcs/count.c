/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:27:11 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 17:27:49 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int	count_digits(char **num)
{
	int		count;

	while (**num == ' ')
		++(*num);
	while (**num == '0')
	{
		if (*(*num + 1) == 0)
			return (1);
		++(*num);
	}
	count = 0;
	while ((*num)[count] && (*num)[count] >= '0' && (*num)[count] <= '9')
		count++;
	return (count);
}
