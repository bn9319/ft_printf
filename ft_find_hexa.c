#include "ft_printf.h"

int ft_find_hexa(const char *to_print, va_list ap, int j)
{
  t_flags_conversions filled;

  filled.conversion = to_print[j];
  ft_set_to_zero(&filled);
  ft_filler(to_print, &filled, ap);
  if (filled.point > 0 && filled.zero > 0)
    {
      filled.right = filled.zero;
      filled.zero = 0;
    }
  filled.unumber = va_arg(ap, unsigned int);
  if (filled.unumber == 0 && filled.point >= 0)
    filled.check = 1;
  ft_length_unsigned(&filled);
  if (filled.point > filled.length && filled.right > 0)
    filled.right -= filled.point;
  if (filled.point >= filled.length && filled.left > 0)
    filled.left -= filled.point;
  ft_write_hexa(filled, filled.length);
  return (filled.i);
}
