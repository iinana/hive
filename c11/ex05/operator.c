/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:42:53 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 14:03:52 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	define_sign(char **num)
{
	int		sign;

	while (**num && is_whitespace(**num))
		++(*num);
	sign = 0;
	while (**num && (**num == '-' || **num == '+'))
	{
		if (**num == '-')
			sign++;
		++(*num);
	}
	if (sign % 2)
		return (-1);
	return (1);
}

int	operate(int n1, int n2, char op)
{
	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (op == '/')
		return (n1 / n2);
	if (op == '%')
		return (n1 % n2);
	return (0);
}
