/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:30:45 by injung            #+#    #+#             */
/*   Updated: 2024/01/15 18:42:13 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

int main(void)
{
	char s[] = "I'm super struggle. but I will struggle more after this. struggle";
	printf("%s %s\n", ft_strstr(s, "ggle "), strstr(s, "ggle "));
	printf("%s %s\n", ft_strstr(s, "happy"), strstr(s, "happy"));
	printf("%s %s\n", ft_strstr(s, "struggli"), strstr(s, "struggli"));
}
