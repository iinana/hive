/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:09:31 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 21:04:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_a_or_d(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	is_lowcase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	else
		return (0);
}

int	is_upcase(char c)
{
	if ((c >= 'A') && (c <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		idx;

	if (is_lowcase(str[0]) == 1)
		str[0] -= 32;
	idx = 1;
	while (str[idx] != 0)
	{
		if (is_upcase(str[idx]) && is_a_or_d(str[idx - 1]))
			str[idx] += 32;
		else if (is_lowcase(str[idx]) && !(is_a_or_d(str[idx - 1])))
			str[idx] -= 32;
		idx++;
	}
	return (str);
}
