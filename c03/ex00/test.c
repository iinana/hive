/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:40:43 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 10:33:54 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s1 != 0)
		return (1);
	if (*s2 != 0)
		return (1);
	return (0);
}

int main(void)
{
	char str1[] = "apple";
	char str2[] = "banana";

	printf("%s, %s, %d\n", str1, str2, ft_strcmp(str1, str2));
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, "apple"));
	printf("%d\n", strcmp(str1, "apple"));
	printf("%s, %s, %d\n", str1, "appla", ft_strcmp(str1, "appla"));
	printf("%d\n", strcmp(str1, "appla"));
}
