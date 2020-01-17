/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_to_zero.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:17:21 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 22:04:26 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_to_zero(t_flags_conversions *filled)
{
	filled->left = 0;
	filled->right = 0;
	filled->zero = 0;
	filled->point = -1;
	filled->number = 0;
	filled->length = 0;
	filled->check = 0;
	filled->i = 0;
	filled->total = 0;
}
