/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:52:51 by injung            #+#    #+#             */
/*   Updated: 2024/01/29 13:57:36 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>

int		is_whitespace(char c);
int		define_sign(char **str);
int		operate(int n1, int n2, char op);

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *nb);

#endif
