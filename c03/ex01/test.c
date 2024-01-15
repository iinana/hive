/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:56:18 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 21:55:58 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	if (i < n)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
	}
	return (0);
}

int main(void)
{
	printf("apple appkd %d", ft_strncmp("apple", "appkd", 3));
	printf(", %d\n", strncmp("apple", "appkd", 3));
	printf("apple danana %d", ft_strncmp("apple", "danana", 4));
	printf(", %d\n", strncmp("apple", "danana", 4));

	printf("apple, appleap %d, %d", ft_strncmp("apple", "apleap", 6), strncmp("apple", "apleap", 6));
}
