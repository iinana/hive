/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:30:17 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 18:38:46 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str != 0)
	{
		if ((*str < 'a') || (*str > 'z'))
			return (0);
		str++;
	}
	return (1);
}

int main(void)
{
	printf("%d %d", ft_str_is_lowercase("dfadjlfad"), ft_str_is_lowercase("ADkafl842"));
			}
