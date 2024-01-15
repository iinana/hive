/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:00:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 14:45:38 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	while (idx < (size - 1))
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (len);
}

int main(void)
{
	printf("%d", ft_strlcpy("a", "bd", 0));
}
