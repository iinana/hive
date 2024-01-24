/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: injung <injung@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:36:37 by injung            #+#    #+#             */
/*   Updated: 2024/01/24 16:48:32 by injung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define BIGGER(Value1, Value2) (Value1 > Value2)
# define ABS(Value) (Value) * BIGGER(Value, -Value)\
	+ (-(Value)) * BIGGER(-Value, Value)

#endif
