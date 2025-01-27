/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_s.c                                        :+:    :+:          */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 22:00:21 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 18:59:57 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strlen_s(t_flags_conversions *filled, char *s)
{
	int		i;

	i = 0;
	if (s == 0)
	{
		filled->length = 6;
		filled->check = 1;
		return ;
	}
	while (s[i] != 0)
		i++;
	filled->length = i;
}
