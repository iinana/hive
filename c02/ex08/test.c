/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:57:26 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 20:59:00 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowercase(char *str)
{
	char	*init;

	init = str;
	while (*str != 0)
	{
		if ((*str >= 'A') && (*str <= 'Z'))
			*str += 32;
		str++;
	}
	return (init);
}

int main(void)
{
	char str[] = "aPPlE";
	printf("%s %s", ft_strlowercase(str), str);
}
