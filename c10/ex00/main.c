/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:31:48 by injung            #+#    #+#             */
/*   Updated: 2024/01/25 16:56:25 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int				infile;
	unsigned char	buf;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("File name missing.\n");
		else
			ft_putstr("Too many arguments.\n");
		return (0);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	while (read(infile, &buf, 1) > 0)
		write(1, &buf, 1);
	close(infile);
}
