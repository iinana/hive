/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:05:32 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 14:09:23 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*c;

	if (argc < 1)
		return (1);
	c = argv[0];
	while (*c)
		write(1, c++, 1);
	write(1, "\n", 1);
	return (0);
}
