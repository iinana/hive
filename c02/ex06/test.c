/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isprintable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:54:10 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 19:01:54 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != 0)
	{
		if ((*str < 32) || (*str > 127))
			return (0);
		str++;
	}
	return (1);
}

int main(void)
{
	printf("%d", ft_str_is_printable(""));
}
