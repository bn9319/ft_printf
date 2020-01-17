/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_length_number.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:14:21 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 22:08:15 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_length_number(t_flags_conversions *filled)
{
	int number;

	number = filled->number;
	if (filled->number == 0 && filled->check == 0)
		filled->length++;
	while (number != 0)
	{
		number /= 10;
		filled->length++;
	}
	if (filled->number < 0)
	{
		filled->right--;
		filled->left--;
		filled->zero--;
	}
}
