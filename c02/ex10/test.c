/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:00:59 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 13:53:28 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		idx;

	idx = 0;
	while (idx < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (size);
}
