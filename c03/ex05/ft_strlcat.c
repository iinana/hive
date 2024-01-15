/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:07 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 19:30:15 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	check_size(char *str)
{
	unsigned int		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dsize;
	unsigned int		ssize;
	unsigned int		i;

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
