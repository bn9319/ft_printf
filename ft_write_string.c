/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 22:11:39 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/03 19:58:34 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putnstr(char *s, int length)
{
	int		i;

	i = 0;
	while (length > 0)
	{
		write(1, &s[i], 1);
		i++;
		length--;
	}
}

void			ft_write_string(t_flags_conversions *filled, char *s, \
int length)
{
	int		i;

	i = 0;
	while ((filled->right > filled->length && (filled->point == -1 || \
filled->point > length)) || (filled->right > filled->point && \
filled->point >= 0 && filled->point <= length))
	{
		write(1, " ", 1);
		filled->right--;
	}
	while (length > 0 && filled->check == 0)
	{
		write(1, &s[i], 1);
		length--;
		i++;
	}
	if (filled->check == 1)
		ft_putnstr("(null)", length);
	while ((filled->left > filled->length && (filled->point > \
filled->length || filled->point == -1)) || (filled->left > filled->point && \
filled->point >= 0 && filled->point <= filled->length))
	{
		write(1, " ", 1);
		filled->left--;
	}
}
