/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:41:02 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 20:43:15 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int unumber)
{
	if (unumber >= 10)
	{
		ft_putunsigned(unumber / 10);
		ft_putchar(unumber % 10 + 48);
	}
	if (unumber < 10 && unumber >= 0)
		ft_putchar(unumber + 48);
}
