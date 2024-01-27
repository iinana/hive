/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:00:24 by injung            #+#    #+#             */
/*   Updated: 2024/01/27 21:47:43 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct DICTIONARY
{
	char **num;
	char **digit;
}	dictionary;

void	ft_putstr(char *str);
int		count_digits(char **num);
char	**init_ary(int size);
int		is_printable(char c);
void	free_2d(char **ary);

int		make_dict(char *path, dictionary *dict);
int		make_dict_digit(int infile, int max_size, char num[4], char ***dict);
int		make_dict_num(int infile, int max_size, char num[4], char ***dict);
char	*make_value(int infile, int max_size);
int		count_max(char *path);

int		write_num(char *num, dictionary dict);

#endif
