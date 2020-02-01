/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hexa.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:03:13 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 19:33:38 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_write_hexa(t_flags_conversions *filled, int length)
{
  while ((filled->right > 0 && filled->point > filled->length) || (filled->right > filled->length && filled->point <= filled->length))
    {
      write(1, " ", 1);
      filled->right--;
    }
  if (filled->conversion == 'p')
	  write(1, "0x", 2);
  while (filled->point > filled->length || filled->zero > filled->length)
    {
      write(1, "0", 1);
      filled->length++;
    }
  if (filled->unumber == 0 && filled->check == 0)
	  write(1, "0", 1);
   if (filled->check == 0)
    ft_puthex1(filled->unumber);
  while ((filled->left > 0 && filled->point >= length) || (filled->left > length && filled->point < length))
    {
      write(1, " ", 1);
      filled->left--;
    }
  filled->length -= length;
}
