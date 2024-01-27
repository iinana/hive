/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:04:08 by injung            #+#    #+#             */
/*   Updated: 2024/01/27 21:47:58 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	char		*num;
	char		*path;
	dictionary	dict;

	if (argc > 3 || argc < 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		num = argv[1];
		path = "numbers.dict";
	}
	else
	{
		num = argv[2];
		path = argv[1];
	}
	dict.num = init_ary(92);
	dict.digit = init_ary(39);
	if (dict.num == NULL || dict.digit == NULL)
		return (1);
	if (!make_dict(path, &dict))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (!write_num(num, dict)) // make a function
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	free_2d(dict.num); // make a function
	free_2d(dict.digit);
	return (0);
}
