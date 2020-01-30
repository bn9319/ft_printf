/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lenght_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:08:06 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/20 20:02:53 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_length_hex(t_flags_conversions *filled)
{
	unsigned int	number;

	number = filled->unumber;
	if (number == 0 && filled->check == 0)
		filled->length++;
	while (number != 0)
	{
		number /= 16;
		filled->length++;
	}
}
