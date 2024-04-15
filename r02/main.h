/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:00:24 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 12:51:05 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define NUM_LEN 92
#define DIGIT_LEN 39

typedef struct DICTIONARY
{
	char **num;
	char **digit;
}	dictionary;

void	free_2d(char **ary, int len);

void	ft_putstr(char *str);
int		count_digits(char **num);
char	**init_ary(int size);
int		is_printable(char c);

int		make_dict(char *path, dictionary *dict);
int		make_dict_digit(int infile, int max_size, char num[4], char ***dict);
int		make_dict_num(int infile, int max_size, char num[4], char ***dict);
char	*make_value(int infile, int max_size);
int		count_max(char *path);

int		check_dictionary(dictionary dict);
int		check_numdict(char **dict);
int		check_digdict(char **dict);

int		write_num(char *num, dictionary dict);
int		recur_write(char *num, int digit, dictionary dict);
int		print_hundred(char *num, int digit, dictionary dict, int flag);
int		print_ten(char *num, int digit, dictionary dict, int flag);
int 	print_one(char *num, int digit, dictionary dict, int flag);

#endif
