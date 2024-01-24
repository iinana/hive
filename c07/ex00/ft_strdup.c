/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:58:44 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 14:13:47 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s, %s\n", ft_strdup(""), strdup(""));
	printf("%s, %s\n", ft_strdup("hello 42"), strdup("hello 42"));
	printf("%s, %s\n", ft_strdup("B7z"), strdup("B7z"));
	printf("%s, %s\n", ft_strdup("dil4bhq73CZDHSPNiaDvISEwi"), 
			strdup("dil4bhq73CZDHSPNiaDvISEwi"));
	printf("%s, %s\n", ft_strdup("2XkqldbJAM55uaiaYncUp8CvTC"), 
			strdup("2XkqldbJAM55uaiaYncUp8CvTC"));
	printf("%s, %s\n", ft_strdup("utWXd03IJVeLVqdrnqM7j"), 
			strdup("utWXd03IJVeLVqdrnqM7j"));
	printf("%s, %s\n", ft_strdup("dpJ"), strdup("dpJ"));
}
*/
