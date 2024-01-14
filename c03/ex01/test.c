/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:56:18 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 10:54:15 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int main(void)
{
	printf("apple appkd %d", ft_strncmp("apple", "appkd", 3));
	printf(", %d\n", strncmp("apple", "appkd", 3));
	printf("apple banana %d", ft_strncmp("apple", "banana", 4));
	printf(", %d\n", strncmp("apple", "banana", 4));
}
