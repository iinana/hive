/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:50:16 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 10:55:31 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		idx;

	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (dest);
}

int main(void)
{
	char c1[10];

	ft_strncpy(c1, "apple", 6);
	printf("%s\n", c1);
	ft_strncpy(c1, "bear", 2);
	printf("%s\n", c1);
}
