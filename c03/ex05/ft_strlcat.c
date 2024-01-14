/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 14:35:10 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
