/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:24:13 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 12:55:03 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// mainly acting function for making dictionary
void	make_dict(int max_size, int infile, t_dictionary *dict)
{
	char	c;
	char	num[10];
	int		i;

	while (read(infile, &c, 1) > 0)
	{
		if (c < '0' || c > '9')
		{
			while (c != '\n' && read(infile, &c, 1) > 0)
				continue ;
			continue ;
		}

		i = 0;
		// save numeric character in num string
		num[i++] = c;
		while (i < 3 && read(infile, &c, 1) > 0 && c >= '0' && c <= '9')
			num[i++] = c;
		num[i] = 0;
		if (i >= 3) // if it is over 90
			make_dict_digit(infile, max_size, num, &(dict->digit));
		else	// if it is under 90
		{
			while (c == ' ' && read(infile, &c, 1) > 0)
				continue ;
			if (c == ':')
				make_dict_num(infile, max_size, num, &(dict->num));
		}
	}
}

// make number(which is under 90) dictionry
// key : integer number (ex. string "20" will be integer 20)
// value : text we should convert to (ex. for key 20, we will have value "twenty")
void	make_dict_num(int infile, int max_size, char num[10], char ***dict)
{
	int		key;

	// make key as integer
	if (!num[1])
		key = num[0] - '0';
	else
		key = (num[0] - '0') * 10 + num[1] - '0';
	// put string(value) to proper location (in index key)
	(*dict)[key] = make_value(infile, max_size);
	return ;
}

// make digits(which is over 100) dictionary
// key : integer of the number of digits (ex. string "1000" will be integer 4)
// value : text we should convert to (ex. for key 4, we will have value "thousand")
void	make_dict_digit(int infile, int max_size, char num[10], char ***dict)
{
	char	c;
	int		key;

	// count the digits 
	if (num[0] != '1')
		return ;
	key = 1;
	while (num[key])
	{
		if (num[key] != '0')
			return ;
		key++;
	}
	while (read(infile, &c, 1) > 0 && c == '0')
		key++;
	while (c == ' ' && read(infile, &c, 1) > 0)
		continue ;
	if (c != ':')
		return ;
	// put string(value) to proper location (in index key)
	(*dict)[key] = make_value(infile, max_size);
	return ;
}

// make string for each number in the dictionary (ex. make "twenty")
char	*make_value(int infile, int max_size)
{
	char			*value;
	unsigned char	c;
	int				i;

	// use max_size which we made in count_max function
	value = (char *)malloc(sizeof(char) * (max_size + 1));
	if (value == NULL)
		return (NULL);
	// skip space
	while (read(infile, &c, 1) > 0 && c == ' ')
		continue ;
	i = 0;
	// put only printable character
	if (is_printable(c))
		value[i++] = c;
	else
		return (NULL);
	while (read(infile, &c, 1) > 0 && c != '\n')
	{
		if (!is_printable(c))
			return (NULL);
		value[i] = c;
		i++;
	}
	value[i] = 0;
	return (value);
}
