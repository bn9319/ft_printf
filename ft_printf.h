/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:44:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/19 14:58:39 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags_conversions{
	int				left;
	int				right;
	int				zero;
	int				point;
	int				number;
	unsigned int	unumber;
	int				length;
	int				i;
	int				check;
	int				total;
	char			conversion;
	char			c;
	char			*string;
}				t_flags_conversions;

int				ft_printf(const char *to_print, ...);
int				ft_find_and_write_conversion(const char *to_print, va_list ap);
int				ft_find_int(const char *to_print, va_list ap, int j);
int				ft_find_char(const char *to_print, va_list ap, int j);
int				ft_find_string(const char *to_print, va_list ap, int j);
int				ft_find_unsigned(const char *to_print, va_list ap, int j);
int				ft_find_percentage(const char *to_print, va_list ap, int j);
int				ft_find_hexa(const char *to_print, va_list ap, int j);
void			ft_set_to_zero(t_flags_conversions *filled);
void			ft_filler(const char *to_print, t_flags_conversions *filled, \
va_list ap);
void			ft_length_number(t_flags_conversions *filled);
void			ft_length_unsigned(t_flags_conversions *filled);
void			ft_strlen_s(t_flags_conversions *filled, char *s);
void			ft_write_int(t_flags_conversions filled, int length);
void			ft_write_char(t_flags_conversions filled);
void			ft_write_string(t_flags_conversions filled, char *s, \
int length);
void			ft_write_unsigned(t_flags_conversions filled, int length);
void			ft_putnumber(int number);
void			ft_putunsigned(unsigned int unumber);
void			ft_putchar(char c);

#endif
