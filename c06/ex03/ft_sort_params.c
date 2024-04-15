/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:23:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/21 14:22:41 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		loc;
	char	*c;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		loc = 1;
		j = 2;
		c = argv[loc];
		while (j < argc)
		{
			if ((*c == -1) || (argv[j][0] != -1 && (ft_strcmp(c, argv[j]) > 0)))
				loc = j;
			j++;
			c = argv[loc];
		}
		ft_putstr(c);
		argv[loc][0] = -1;
		i++;
	}
}
