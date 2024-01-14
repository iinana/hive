/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 14:36:56 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned long	check_size(char *str)
{
	unsigned long		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

unsigned long	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned long		dsize;
	unsigned long		ssize;
	int					i;

	dsize = check_size(dest);
	ssize = check_size(src);
	if (dsize > size)
		return (size + ssize);
	i = dsize;
	while (*src && (i < (size - 1)))
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	i++;
	return (dsize + ssize);
}

int main(void)
{
	char str1[10] = "ab";
	char str2[10] = "cdef";

	printf("%lu %s\n", ft_strlcat(str1, str2, 5), str1);
	char str3[10] = "ab";
	printf("%lu %s\n", strlcat(str3, str2, 5), str3);

	char str4[10] = "abc";
	printf("%lu %s\n", ft_strlcat(str4, str2, 2), str4);
	printf("%lu %s\n", strlcat(str4, str2, 2), str4);
}
