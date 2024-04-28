/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:00:24 by injung            #+#    #+#             */
/*   Updated: 2024/01/28 21:06:32 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define NUM_LEN 92
# define DIGIT_LEN 39

typedef struct DICTIONARY
{
	char	**num;
	char	**digit;
}	t_dictionary;

// main.c file
int		set_init_values(int argc, char **argv, char **in, char **path);
void	free_dict(t_dictionary *dict);

// ft_func.c file
void	ft_putstr(char *str);
char	**init_ary(int size);
int		is_printable(char c);

// dict.c file
void	make_dict(int max_size, int infile, t_dictionary *dict);
void	make_dict_digit(int infile, int max_size, char num[10], char ***dict);
void	make_dict_num(int infile, int max_size, char num[10], char ***dict);
char	*make_value(int infile, int max_size);

// count.c file
int		count_digits(char **num);
int		count_max(char *path);

// check_dict.c file
int		check_dict(t_dictionary dict);
int		check_numdict(char **dict);
int		check_digdict(char **dict);

// print.c file
int		write_num(char *num, t_dictionary dict);
int		iter_write(char *num, int digit, t_dictionary dict);
int		print_hundred(char *num, int digit, t_dictionary dict, int flag);
int		print_ten(char *num, int digit, t_dictionary dict, int flag);
int		print_one(char *num, int digit, t_dictionary dict, int flag);

#endif
