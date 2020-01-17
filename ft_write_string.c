/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 22:11:39 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 00:18:56 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_string(t_flags_conversions filled, char *s, int length)
{
	int		i;

	i = 0;
	while ((filled.right > 0 && filled.point > filled.length) || (filled.right > filled.length && filled.point <= filled.length))
	{
		write(1, " ", 1);
		filled.right--;
	}
	while (length > 0)
	{
		write(1, &s[i], 1);
		length--;
		i++;
	}
	while ((filled.left > 0 && filled.point > filled.length) || (filled.left > filled.length && filled.point <= filled.length))
	{
		write(1, " ", 1);
		filled.left--;
	}
}
