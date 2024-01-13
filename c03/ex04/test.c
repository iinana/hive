/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:30:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 17:59:58 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			j = 0;
			while (to_find[i] && (str[j] == to_find[i]))
			{
				i++;
				j++;
			}
			if (!(to_find[i]))
				return (str);
		}
		str++;
	}
	return (0);
}

int	main(void)
{
	printf("apple, ap, %s\n", ft_strstr("apple", "ap"));
	printf("apple, e, %s\n", ft_strstr("apple", "e"));
	printf("apple, , %s\n", ft_strstr("apple", ""));
	printf("apple, apply, %s\n", ft_strstr("apple", "apply"));
}
