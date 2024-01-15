/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:56:18 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 21:54:26 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	if (i < n)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
	}
	return (0);
}
