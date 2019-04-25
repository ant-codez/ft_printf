/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:49:35 by achavez           #+#    #+#             */
/*   Updated: 2019/04/24 14:56:24 by achavez          ###   ########.fr       */
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
	int		width;
	char	*str;
	char	*tmp;

	o = va_arg(p->arg, int);
	str = ft_itoa_base(o, 8);
	p->flags[1] == '#' ? str = ft_strjoin("0", str) : 0;
	width = 0;
	if (p->precision > (int)ft_strlen(str))
		tmp = handle_precision_int(str, p->precision - (int)ft_strlen(str));
	if (p->width > (int)ft_strlen(str))
	{
		width = 1;
		if (tmp[0] != '\0')
			p->str = handle_width_int(tmp, p);
		else
			p->str = handle_width_int(str, p);
	}
	if (width == 1)
		ft_putstr(p->str);
	else if (tmp[0] != '\0')
		ft_putstr(tmp);
	else
		ft_putstr(str);
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
	int		num;
	int		width;
	char	*s;
	char	*pre;

	num = va_arg(p->arg, int);
	s = ft_itoa(num);
	if (num > 0 && p->flags[2] == '+')
		s = ft_strjoin("+", s);
	width = 0;
	if (p->precision > (int)ft_strlen(s))
		pre = handle_precision_int(s, p->precision - (int)ft_strlen(s));
	if (p->width > (int)ft_strlen(s))
	{
		if (pre[0] != '\0')
			p->str = handle_width_int(pre, p);
		else
			p->str = handle_width_int(s, p);
		width = 1;
	}
	if (width == 1)
		ft_putstr(p->str);
	else if (pre[0] != '\0')
		ft_putstr(pre);
	else
		ft_putstr(s);
}

void	print_f(t_data *p)
{
	double f;

	f = va_arg(p->arg, double);
	ft_putfloat(f);
}
