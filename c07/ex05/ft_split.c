/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:17:39 by injung            #+#    #+#             */
/*   Updated: 2024/01/22 22:23:16 by injung           ###   ########.fr       */
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

char	*make_elem(char **str)
{
	int		len;
	int		i;
	char	*elem;

	len = 0;
	while ((*str)[len] != 0 && (*str)[len] != -1)
		len++;
	elem = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		elem[i] = (*str)[i];
		i++;
	}
	elem[i] = 0;
	return (elem);
}

void	split_point(char **str, char *charset)
{
	int		i;
	int		j;

	i = 0;
	while ((*str)[i])
	{
		j = 0;
		while (charset[j])
		{
			if ((*str)[i] == charset[j])
			{
				(*str)[i] = -1;
				break ;
			}
			j++;
		}
		i++;
	}
}

char **ft_split(char *str, char *charset)
{
	int		i;
	char	**res;
	int		len;

	len = ft_strlen(str);
	res = (char **)malloc((len * 2 + 1) * 4);
	split_point(&str, charset);
	i = 0;
	while (*str)
	{
		if (*str != -1)
			res[i++] = make_elem(&str);
		str++;
	}
	res[i] = 0;
	return (res);
}

#include <stdio.h>
int	main(void)
{
	char **res = ft_split("hello,how are you?I'm good!!yeah", ", ?!");
	int i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
