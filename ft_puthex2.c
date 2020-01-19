/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:50:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/19 16:53:07 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_puthex2(int number)
{
	if (number >= 10)
	{
		ft_puthex2(number / 16);
		ft_putchar(number % 16 + 48);
	}
	if (number < 10)
	{
		ft_putchar(number % 16 + 48);
	}
}
