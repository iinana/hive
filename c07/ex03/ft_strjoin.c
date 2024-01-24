/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:09:01 by injung            #+#    #+#             */
/*   Updated: 2024/01/23 16:37:14 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcat(char *des, char *src)
{
	while (*des)
		des++;
	while (*src)
	{
		*des = *src;
		src++;
		des++;
	}
	*des = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(sep) * size;
	while (i < size)
		len += ft_strlen(strs[i++]);
	res = (char *)malloc(4 * (len + 1));
	if (!res)
		return (0);
	res[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i != (size - 1))
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%s", ft_strjoin(argc, argv, ", "));
}
*/
