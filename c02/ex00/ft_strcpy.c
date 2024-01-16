/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:19:02 by injung            #+#    #+#             */
/*   Updated: 2024/01/14 13:59:31 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		idx;

	idx = 0;
	while (src[idx] != 0)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

int main(void)
{
    char s1[10];
    char s2[10] = "Abc";
    char *s = ft_strcpy(dest, src);
    return (0);
}
