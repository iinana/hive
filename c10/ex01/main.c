/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:55:35 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 09:18:21 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	put_error(char *path)
{
	if (errno == 0)
		return (0);
	ft_putstr("./ft_cat: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);

}

int	print_single_file(char *file)
{
	int				infile;
	unsigned char	buf;

	infile = open(file, O_RDONLY);
	if (infile < 0)
		return (0);
	while (read(infile, &buf, 1) > 0)
		write(1, &buf, 1);
	close(infile);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		put_error(0);
	i = 1;
	while (i < argc)
	{
		if (print_single_file(argv[i]) == 0)
		{
			if (put_error(argv[i]))
				return (0);
		}
		i++;
	}
}
