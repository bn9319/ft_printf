#include "ft_printf.h"

void ft_write_hexa(t_flags_conversions filled, int length)
{
  while ((filled.right > 0 && filled.point > filled.length) || (filled.right > filled.length && filled.point <= filled.length))
    {
      write(1, " ", 1);
      filled.right--;
    }
  while (filled.point > filled.length || filled.zero > filled.length)
    {
      write(1, "0", 1);
      filled.length++;
    }
  if (filled.check == 0)
    ft_puthex1(filled.unumber);
  while ((filled.left > 0 && filled.point > length) || (filled.left > length && filled.point <= length))
    {
      write(1, " ", 1);
      filled.left--;
    }
}
