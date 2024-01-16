/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:00:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 21:31:03 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
