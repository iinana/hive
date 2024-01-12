/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:02:52 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 20:29:18 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_sttrupcase(char *str)
{
	char	*init;

	init = str;
	while (*str != 0)
	{
		if ((*str >= 'a') && (*str <= 'z'))
			*str -= 32;
		str++;
	}
	return (init);
}

int main(void)
{
	char str[] = "AppLE";
	printf("%s %s", ft_sttrupcase(str), str);
}
