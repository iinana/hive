/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:49:28 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 18:59:03 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str != 0)
	{
		if ((*str < 'A') || (*str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}

int main(void)
{
	printf("%d %d", ft_str_is_uppercase("DFADAd"), ft_str_is_uppercase("DAFDE"));
}
