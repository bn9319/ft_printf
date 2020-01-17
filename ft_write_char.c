/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:22:30 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 21:40:51 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(t_flags_conversions filled)
{
	while (filled.right > 0)
	{
		write(1, " ", 1);
		filled.right--;
	}
	ft_putchar(filled.c);
	while (filled.left > 0)
	{
		write(1, " ", 1);
		filled.left--;
	}	
}
