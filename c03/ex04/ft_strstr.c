/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:30:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/13 17:58:47 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			j = 0;
			while (to_find[i] && (str[j] == to_find[i]))
			{
				i++;
				j++;
			}
			if (!(to_find[i]))
				return (str);
		}
		str++;
	}
	return (0);
}
