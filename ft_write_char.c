/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:22:30 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 16:22:02 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(t_flags_conversions *filled)
{
	while (filled->right > 0)
	{
		write(1, " ", 1);
		filled->right--;
	}
	if (filled->check == 1)
	{
		while (filled->zero > 1)
		{
			write(1, "0", 1);
			filled->zero--;
		}
	}
	ft_putchar(filled->c);
	while (filled->left > 0)
	{
		write(1, " ", 1);
		filled->left--;
	}
}
