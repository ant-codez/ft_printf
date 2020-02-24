/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:11:56 by achavez           #+#    #+#             */
/*   Updated: 2020/02/23 17:37:33 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_p(t_data *p)
{
	int		x;
	char	*str;

	x = va_arg(p->arg, int);
	str = ft_itoa_base(x, 16);
	p->str = ft_strjoin("0x10", str);
	ft_strlower(p->str);
	if (p->width > 11 && p->flags[3] == '-')
	{
		ft_putstr(p->str);
		while (p->width-- > 11)
			ft_putchar(' ');
	}
	else
	{
		while (p->width-- > 11)
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
		ft_putstr(p->str);
	}
}

void	print_c(t_data *p, int percent)
{
	int		c;

	if (percent == 42)
		c = '%';
	else
		c = va_arg(p->arg, int);
	if (p->width > 1 && p->flags[3] == '-')
	{
		ft_putchar(c);
		while (p->width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (p->width-- > 1)
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
		ft_putchar(c);
	}
}

void	print_u(t_data *p)
{
	uintmax_t	num;

	num = oux_length(p);
	if (p->flags[3] == '-')
	{
		print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_getdigits(num), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr(num);
		if (p->width > ft_getdigits(num))
			handle_u_width_intV2(num, ft_getdigits(num), p);
	}
	else
	{
		if (p->width > ft_getdigits(num))
		{
			if (p->flags[0] == '0' && p->precision == -1)
				print_symbols(p, 3, (int)num);
			handle_u_width_intV2(num, ft_getdigits(num), p);
			if (p->flags[0] != '0' || (p->flags[0] == '0' &&
				(p->width > p->precision) && p->precision != -1))
				print_symbols(p, 3, (int)num);
		}
		else
			print_symbols(p, 3, (int)num);
		handle_u_precision_intV2(num, ft_getdigits(num), p);
		if (p->precision != 0 && p->precision != -2)
			ft_putnbr(num);
	}
}
