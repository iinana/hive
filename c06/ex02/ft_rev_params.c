/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:11:46 by injung            #+#    #+#             */
/*   Updated: 2024/01/18 13:15:32 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*c;

	while (argc > 1)
	{
		argc--;
		c = argv[argc];
		while (*c)
			write(1, c++, 1);
		write(1, "\n", 1);
	}
}
