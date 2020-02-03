/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:44:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/03 19:43:09 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags_conversions{
	int					left;
	int					right;
	int					zero;
	int					point;
	long int			number;
	unsigned long		unumber;
	int					length;
	int					i;
	int					check;
	int					total;
	char				conversion;
	char				c;
	char				*string;
}				t_flags_conversions;

int				ft_printf(const char *to_print, ...);
int				ft_find_and_write_conversion(const char *to_print, va_list ap, \
int *counter);
int				ft_find_int(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_char(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_string(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_unsigned(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_percentage(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_hexa(const char *to_print, va_list ap, int j, \
int *counter);
int				ft_find_hexb(const char *to_print, va_list ap, int j, \
int *counter);
void			ft_set_to_zero(t_flags_conversions *filled);
void			ft_filler(const char *to_print, t_flags_conversions *filled, \
va_list ap);
void			ft_length_number(t_flags_conversions *filled);
void			ft_length_unsigned(t_flags_conversions *filled);
void			ft_length_hex(t_flags_conversions *filled);
void			ft_strlen_s(t_flags_conversions *filled, char *s);
void			ft_write_int(t_flags_conversions *filled, int length);
void			ft_write_char(t_flags_conversions *filled);
void			ft_write_string(t_flags_conversions *filled, char *s, \
int length);
void			ft_write_unsigned(t_flags_conversions *filled, int length);
void			ft_write_hexa(t_flags_conversions *filled, int length);
void			ft_write_hexb(t_flags_conversions *filled, int length);
void			ft_putnumber(long int number);
void			ft_putunsigned(unsigned long unumber);
void			ft_putchar(char c);
void			ft_puthex1(unsigned long number);
void			ft_puthex2(unsigned long number);
#endif
