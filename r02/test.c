/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:04:08 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 10:39:22 by injung           ###   ########.fr       */
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
	printf("argument fault pass\n");
	if (argc == 2)
	{
		num = argv[1];
		path = "./numbers.dict";
	}
	else
	{
		num = argv[2];
		path = argv[1];
	}
	printf("after set num and path\n");
	dict.num = init_ary(NUM_LEN);
	dict.digit = init_ary(DIGIT_LEN);
	if (dict.num == NULL || dict.digit == NULL)
		return (1);
	printf("dict initialize\n");
	if (!make_dict(path, &dict))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	printf("make dictionary\n");
	printf("%s\n", (dict.num)[3]);
	if (!write_num(num, dict))
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
