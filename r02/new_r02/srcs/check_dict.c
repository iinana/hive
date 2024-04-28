/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:42:42 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 12:41:17 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_dict(t_dictionary dict)
{
	if (!check_numdict(dict.num)) // check number part (0 to 90)
		return (0);
	if (!check_digdict(dict.digit)) // check digit part (from 100)
		return (0);
	return (1);
}

// check if dictionary have all the initial entries.
int	check_numdict(char **dict)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (dict[i] == 0)
			return (0);
		i++;
	}
	while (i <= 90)
	{
		if (dict[i] == 0)
			return (0);
		i += 10;
	}
	return (1);
}

int	check_digdict(char **dict)
{
	int		i;

	if (dict[3] == 0)
		return (0);
	i = 4;
	while (i <= 37)
	{
		if (dict[i] == 0)
			return (0);
		i += 3;
	}
	return (1);
}
