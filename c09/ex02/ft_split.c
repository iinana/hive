/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:31:20 by injung            #+#    #+#             */
/*   Updated: 2024/01/25 15:31:25 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	if (!(*charset))
		return (0);
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcpy(char *des, char *src)
{
	while (*src)
	{
		*des = *src;
		des++;
		src++;
	}
}

char	*create_string(char *str, char *charset)
{
	int		len;
	char	*res;
	int		i;

	len = 0;
	while (str[len] && !(is_charset(str[len], charset)))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;

	res = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!res)
		return (0);
	if (!(*str))
	{
		res[0] = 0;
		return (res);
	}
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			res[i] = create_string(str, charset);
			str += ft_strlen(res[i++]);
		}
		else
			str++;
	}
	res[i] = 0;
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	int	i = 0;
	char **str = ft_split("", "");
	while (str[i] != 0)
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}
}
*/
