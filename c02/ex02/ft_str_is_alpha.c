/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@studnet.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:56:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/12 11:57:27 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_is_alpha(char c)
{
	if ((c >= 'A') && (c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	while (*str != 0)
	{
		if (char_is_alpha(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
