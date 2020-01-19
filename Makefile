#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bnijland <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/13 18:53:47 by bnijland      #+#    #+#                  #
#    Updated: 2020/01/19 13:49:19 by bnijland      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_printf.c ft_find_and_write_conversion.c ft_find_int.c ft_set_to_zero.c ft_filler.c ft_length_number.c ft_write_int.c ft_putnumber.c ft_find_char.c ft_write_char.c ft_putchar.c ft_find_string.c ft_strlen_s.c ft_write_string.c ft_find_unsigned.c ft_length_unsigned.c ft_write_unsigned.c ft_putunsigned.c ft_find_percentage.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		r- f $(NAME)
re: fclean all