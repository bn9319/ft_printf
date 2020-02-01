/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_percentage.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 13:45:52 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 17:06:26 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_percentage(const char *to_print, va_list ap, int j, int *counter)
{
	t_flags_conversions filled;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	filled.right--;
	filled.left--;
	filled.c = '%';
	filled.check = 1;
	filled.total = filled.right + filled.left + filled.zero + 1;
	ft_write_char(&filled);
	*counter += filled.total - filled.right - filled.left - filled.zero;
	return (filled.i);
}
