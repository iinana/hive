/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:04:08 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 12:42:48 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	char			*in; 	// input number string which we have to convert
	char			*p;	 	// dictionary file path	
	int				inf; 	// input file  
	t_dictionary	dict;   // dictionary which we will make with dictionary file

	// set the p(path) and in(input number)
	if (!set_init_values(argc, argv, &in, &p))
	{
		ft_putstr("Error\n");
		return (0);
	}

	// initialize array in dictionary (set all the elements as 0)
	dict.num = init_ary(NUM_LEN);
	if (dict.num == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	dict.digit = init_ary(DIGIT_LEN);
	if (dict.digit == NULL)
	{
		free(dict.num);
		ft_putstr("Error\n");
		return (0);
	}

	// open file in path
	inf = open(p, O_RDONLY);
	// make a dictionary
	make_dict(count_max(p), inf, &dict);

	// check if dictionary is valid, and if it is write num 
	if (!check_dict(dict))
	{
		close(inf);
		free_dict(&dict);  // have mistake
		ft_putstr("Dict Error\n");
		return (0);
	}
	if (!write_num(in, dict))
		ft_putstr("Error\n");
		
	// deallocate the dictionary memory and close file
	free_dict(&dict);
	close(inf);
	return (0);
}

int	set_init_values(int argc, char **argv, char **in, char **path)
{
	// if main got only one parameter => that parameter is input number (using default file)
	if (argc == 2)
	{
		(*in) = argv[1];
		(*path) = "numbers.dict";
	}
	// if main got two parameters => first is file path, second is input number
	else if (argc == 3)
	{
		(*in) = argv[2];
		(*path) = argv[1];
	}
	else {
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

void	free_dict(t_dictionary *dict)
{
	int		i;

	i = 0;
	while (i < NUM_LEN)
		free((dict->num)[i++]);
	free(dict->num);
	i = 0;
	while (i < DIGIT_LEN)
		free((dict->digit)[i++]);
	free(dict->digit);
}
