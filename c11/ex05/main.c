/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:28:04 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 12:55:39 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	int		res;
	char	op;

	n1 = define_sign(argv + 1); // make function
	n2 = define_sign(argv + 3); // return 1 or -1 // 0 means invalid input
	if (s1 == 0 || s2 == 0)
		return (0);
	op = argv[2][0];
	n1 *= ft_atoi(argv[1]); // make function
	n2 *= ft_atoi(argv[3]);
	if (n2 == 0 && (op == '/' || op == '%'))
	{
		ft_putstr("Stop : "); // make function
		if (op == '/')
			ft_putstr("division");
		else
			ft_putstr("modulo");
		ft_putstr(" by zero");
		return (0);
	}
	res = operate(n1, n2, op); // make function, return 0 when op invalid
	ft_putnbr(res);	// make function
}
