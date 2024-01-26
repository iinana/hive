/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:20:39 by injung            #+#    #+#             */
/*   Updated: 2024/01/26 11:52:51 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	if (!*tab)
		return (0);
	while (*tab)
	{
		if (!(*f)(*tab))
			return (0);
		++tab;
	}
	return (1);
}

/*
#include <stdio.h>
int is_lowcase(char *c)
{
	while (*c)
	{
		if ((*c < 'a') || (*c > 'z'))
			return (0);
		c++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	printf("%d", ft_any(argv+1, &is_lowcase));
}
*/
