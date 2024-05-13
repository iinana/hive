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

// map 형성을 위한 정보를 담은 구조체
typedef struct INFO
{
	unsigned int	x;	// map row 개수
	unsigned int	y;  // map column 개수
	char			empt;	// empty 문자
	char			obst;	// obstacle 문자
	char			full;	// full 문자
}	t_info;

// 결과값을 담은 구조체
// -> x, y 좌표에서 시작하는 size 길이의 변을 가진 정사각형의 결과값
typedef struct RESULT
{
	unsigned int	size;
	unsigned int	x;
	unsigned int	y;
}	t_result;

// main.c
void		print_map(char **map, t_info info);
void		print_res(t_result res, char **map, t_info info);

// ft_func.c
void			ft_putstr(char *str);
unsigned int	ft_atoi(char *str, int len);
unsigned int	count_line(int infile);
void			ft_strncpy(char *dest, char *src, unsigned int n);

// file_map.c (파일 입력 받았을 때 map 만드는 함수)
char			**make_file_map(char *path, t_info *info);
int				fill_file_info(char	*path, t_info *info);

// std_map.c (std 입력 받았을 때 map 만드는 함수)
char		**make_std_map(t_info *info);
int				fill_std_info(t_info *info);
void			set_info(t_info *info, int i, char signs[3]);
char			**fill_map(t_info *info, unsigned int x);
unsigned int	make_first_line(t_info *info, char **line, unsigned int size);

// ft_map.c (map 만들 때, file과 std에서 공통으로 사용되는 helper function)
void			set_chars(t_info *info, char e, char o, char f);
char	*map_array(int infile, unsigned int x, t_info *info);
int				is_allowed(char c, t_info *info);

// square.c (결과값인 정사각형을 찾는 함수)
t_result		find_square(char **map, t_info info);
int				recur_square(t_result *res, char **map, t_info info);
unsigned int	check_obst(t_result *res, char **map, char obst);

#endif
