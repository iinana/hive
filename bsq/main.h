/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:20:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/31 19:24:59 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct INFO
{
	unsigned int	x;
	unsigned int	y;
	char			empt;
	char			obst;
	char			full;
}	t_info;

typedef struct RESULT
{
	unsigned int	size;
	unsigned int	x;
	unsigned int	y;
}	t_result;

// main.c
char		**make_std_map(t_info *info);
void		print_map(char **map, t_info info);
void		print_res(t_result res, char **map, t_info info);

// ft_func.c
void			ft_putstr(char *str);
unsigned int	ft_atoi(char *str, int len);
unsigned int	count_line(int infile);
void			ft_strncpy(char *dest, char *src, unsigned int n);

// file_map.c
char			**make_file_map(char *path, t_info *info);
int				fill_file_info(char	*path, t_info *info);
char			*map_array(int infile, t_info *info);
int				is_allowed(char c, t_info *info);

// std_map.c
char			**fill_map(t_info *info, unsigned int x);
int				fill_std_info(t_info *info);
void			set_info(t_info *info, int i, char signs[4]);
void			set_chars(t_info *info, char e, char o, char f);
unsigned int	make_first_line(t_info *info, char **line, unsigned int size);

// square.c
t_result		find_square(char **map, t_info info);
int				recur_square(t_result *res, char **map, t_info info);
unsigned int	check_obst(t_result *res, char **map, char obst);

#endif
