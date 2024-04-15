/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:20:41 by injung            #+#    #+#             */
/*   Updated: 2024/01/30 21:42:30 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct INFO
{
	int		x;
	int		y;
	char	empt;
	char	obst;
	char	full;
}	t_info;

typedef struct RESULT
{
	int		size;
	int		x;
	int		y;
}	t_result;

// main.c
void		print_res(t_result res, char **map, t_info info);

// ft_func.c
void		ft_putstr(char *str);
int			ft_atoi(char *str, int len);
int			count_line(int infile);

// map.c
char		**make_map(char *path, t_info *info);
int			fill_info(char	*path, t_info *info);
char		*map_array(int infile, t_info *info);
int			is_allowed(char c, t_info *info);

// square.c
t_result	find_square(char **map, t_info info);
int			recur_square(t_result *res, char **map, t_info info);
int			check_obst(t_result *res, char **map, char obst);

#endif
