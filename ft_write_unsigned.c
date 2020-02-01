/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:36:35 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 19:32:39 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_unsigned(t_flags_conversions *filled, int length)
{
	while ((filled->right > 0 && filled->point > filled->length) || \
		   (filled->right > filled->length && filled->point <= filled->length))
	{
		write(1, " ", 1);
		filled->right--;
	}
	while (filled->point > filled->length || filled->zero > filled->length)
	{
		write(1, "0", 1);
		filled->length++;
	}
	if (filled->check == 0)
		ft_putunsigned(filled->unumber);
	while ((filled->left > 0 && filled->point >= length) || \
		   (filled->left > length && filled->point < length))
	{
		write(1, " ", 1);
		filled->left--;
	}
	filled->length -= length;
}
