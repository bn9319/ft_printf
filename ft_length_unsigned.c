/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_length_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:33:38 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 20:35:49 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_length_unsigned(t_flags_conversions *filled)
{
	unsigned number;

	number = filled->unumber;
	if (filled->unumber == 0 && filled->check == 0)
		filled->length++;
	while (number != 0)
	{
		number /= 10;
		filled->length++;
	}
}
