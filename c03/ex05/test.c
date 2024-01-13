/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 19:17:11 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_size(char *str)
{
	int		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		dsize;
	int		ssize;
	int		i;

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
	char s1[10] = "apple";
	char s2[] = "banana";

	printf("%d, %s", ft_strlcat(s1, s2, 8), s1);
}
