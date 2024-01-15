/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 19:28:10 by injung           ###   ########.fr       */
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
	unsigned long		i;

	dsize = check_size(dest);
	ssize = check_size(src);
	if ((size == 0) || (dsize >= size))
		return (size + ssize);
	i = dsize;
	while (*src && (i < (size - 1)))
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dsize + ssize);
}

int main(void)
{
	char dest[20] = "pouic pouic";
	char src[] = "p";
	unsigned int size = 5;
	unsigned int result;

	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
	result = strlcat(dest, src, size);
	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);
}
