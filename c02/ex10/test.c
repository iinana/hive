/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:00:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 21:32:31 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		idx;
	unsigned int		len;

	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	idx = 0;
	while (src[idx] && (idx < (size - 1)))
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	return (len);
}

int	main(void)
{
	char s1[30] = "hello world!!!!!";
	char s2[30] = "hello world!!!!!";
	char s3[30] = "hello world";

	ft_strlcpy(s1, s3, 12);
	strlcpy(s2, s3, 12);
	printf("%s  %s\n", s1, s2);
	printf("%c %c", s1[12], s2[12]);
}
