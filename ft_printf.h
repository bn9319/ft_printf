/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:44:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/05 18:35:32 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>

typedef struct	s_flags_conversions_int{
	int l_justify;
	int r_justify;
	int	zero;
	int	point;
	int star;
}				t_flags_conversions_int;

t_flags_conversions_int ft_filler_int(const char *to_print);

#endif
