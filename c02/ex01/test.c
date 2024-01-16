/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:50:16 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 20:56:40 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		idx;

	idx = 0;
	while (src[idx] && (idx < n))
	{
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < n)
	{
		dest[idx] = 0;
		idx++;
	}
	return (dest);
}

int	main(void)
{
	char s1[30] = "hello world!!!!!!";
	char s2[30] = "hello world!!!!!!";

	printf("%s %s\n", ft_strncpy(s1, "hello world!", 12), s1);
	printf("%s %s\n", strncpy(s2, "hello world!", 12), s2);
	printf("%c %c", s1[12], s2[12]);
}
