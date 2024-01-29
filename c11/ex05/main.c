/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:28:04 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 14:02:08 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	char	op;

	if (argc != 4)
		return (0);
	n1 = define_sign(argv + 1);
	n2 = define_sign(argv + 3);
	if (n1 == 0 || n2 == 0)
		return (0);
	op = argv[2][0];
	n1 *= ft_atoi(argv[1]);
	n2 *= ft_atoi(argv[3]);
	if (n2 == 0 && (op == '/' || op == '%'))
	{
		ft_putstr("Stop : ");
		if (op == '/')
			ft_putstr("division");
		else
			ft_putstr("modulo");
		ft_putstr(" by zero\n");
		return (0);
	}
	ft_putnbr(operate(n1, n2, op));
}
