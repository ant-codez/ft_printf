/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:49:35 by achavez           #+#    #+#             */
/*   Updated: 2019/04/22 20:33:39 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_s(t_data *p)
{
	char	*s;

	s = va_arg(p->arg, char *);
	print_str(s, p);
}

void	print_o(t_data *p)
{
	int 	o;
	char	*str;
	int		len;

	o = va_arg(p->arg, int);
	str = ft_itoa_base(o, 8);
	len = ft_strlen(str);
	while (--p->width > len)
		ft_putchar(' ');
	if (p->precision > len)
	{
		while (--p->precision >= len)
			ft_putchar('0');
		ft_putstr(str);
	}
	else
	{
		p->flags[1] == '#' ? p->str = ft_strjoin("0", str) : (p->str = str);
		ft_putstr(p->str);
	}
}

void	print_x(t_data *p)
{
	int 	x;
	char	*str;

	x = va_arg(p->arg, unsigned int);
	str = ft_itoa_base(x, 16);
	if (p->flags[1] == '#')
	{
		p->str = ft_strjoin("0X", str);
		if (*p->traverse == 'x')
			ft_strlower(p->str);
		ft_putstr(p->str);
	}
	else
	{
		if (*p->traverse == 'x')
			ft_strlower(str);
		ft_putstr(str);
	}
}

void	print_di(t_data *p)
{
	int num;
	int digits;

	num = va_arg(p->arg, int);
	digits = ft_getdigits(num);
	while (--p->precision > digits)
		ft_putnbr(0);
	while (--p->width >= digits)
		ft_putchar(' ');
	ft_putnbr(num);
}

void	print_f(t_data *p)
{
	double f;

	f = va_arg(p->arg, double);
	ft_putfloat(f);
}
