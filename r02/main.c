/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:04:08 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 17:12:09 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	char		*inputn;
	char		*path;
	dictionary	dict;

	if (argc > 3 || argc < 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		inputn = argv[1];
		path = "numbers.dict";
	}
	else
	{
		inputn = argv[2];
		path = argv[1];
	}
	dict.num = init_ary(NUM_LEN);
	dict.digit = init_ary(DIGIT_LEN);
	if (dict.num == NULL || dict.digit == NULL)
		return (1);
	if (!make_dict(path, &dict) || !check_dictionary(dict))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (!write_num(inputn, dict))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	free_2d(dict.num, NUM_LEN);
	free_2d(dict.digit, DIGIT_LEN);
	return (0);
}

void	free_2d(char **ary, int len)
{
	int		i;

	i = 0;
	while (i < len)
		free(ary[i++]);
	free(ary);
}
