/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:50:16 by injung            #+#    #+#             */
/*   Updated: 2024/01/16 14:11:45 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		idx;

	idx = 0;
	while (src[idx] && (idx < n))
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	idx++;
	while (idx < n)
	{
		dest[idx] = 0;
		idx++;
	}
	return (dest);
}
