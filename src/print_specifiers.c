/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:49:35 by achavez           #+#    #+#             */
/*   Updated: 2019/06/21 20:15:24 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_s(t_data *p)
{
	char	*s;

	s = va_arg(p->arg, char *);
	if (s == NULL)
		print_str("(null)", p);
	else
		print_str(s, p);
}

void	print_o(t_data *p)
{
	uintmax_t 	o;
	char			*str;
	char			*tmp;

	o = oux_length(p);
	str = ft_itoa_base_u(o, 8);
	p->flags[1] == '#' ? str = ft_strjoin("0", str) : 0;
	if (p->precision > (int)ft_strlen(str))
		tmp = handle_precision_int(str, p->precision - (int)ft_strlen(str));
	if (p->width > (int)ft_strlen(str) && p->width > (int)ft_strlen(tmp))
	{
		if (tmp[0] != '\0')
			tmp = handle_width_int(tmp, p);
		else
			tmp = handle_width_int(str, p);
	}
	if (tmp[0] != '\0')
		ft_putstr(tmp);
	else
		ft_putstr(str);
	tmp[0] != '\0' ? p->reee = (int)ft_strlen(tmp) : (p->reee = (int)ft_strlen(str));
}

void	print_x(t_data *p)
{
	uintmax_t 		x;
	char			*str;
	char			*tmp;

	x = oux_length(p);
	str = ft_itoa_base_u(x, 16);
	p->flags[1] == '#' ? str = ft_strjoin("0X", str) : 0;
	*p->traverse == 'x' ? ft_strlower(str) : 0;
	if (p->precision > (int)ft_strlen(str))
		tmp = handle_precision_int(str, p->precision - (int)ft_strlen(str));
	if (p->width > (int)ft_strlen(str))
	{
		if (tmp[0] != '\0')
			tmp = handle_width_int(tmp, p);
		else
			tmp = handle_width_int(str, p);
	}
	if (tmp[0] != '\0')
		ft_putstr(tmp);
	else
		ft_putstr(str);
	tmp[0] != '\0' ? p->reee = (int)ft_strlen(tmp) : (p->reee = (int)ft_strlen(str));
}

void	print_di(t_data *p)
{
	intmax_t		num;
	char			*s;
	char			*pre;

	num = di_length(p);
	s = ft_itoa(num);
	if (num > 0 && p->flags[2] == '+')
		s = ft_strjoin("+", s);
	if (p->precision > (int)ft_strlen(s))
		pre = handle_precision_int(s, p->precision - (int)ft_strlen(s));
	if (p->width > (int)ft_strlen(s) && p->width > (int)ft_strlen(pre))
	{
		if (pre[0] != '\0')
			pre = handle_width_int(pre, p);
		else
			pre = handle_width_int(s, p);
	}
	if (pre[0] != '\0')
		ft_putstr(pre);
	else
		ft_putstr(s);
	pre[0] != '\0' ? p->reee = (int)ft_strlen(pre) : (p->reee = (int)ft_strlen(s));
}

void	print_f(t_data *p)
{
	double	f;
	char	*tmp;

	f = va_arg(p->arg, double);
	tmp = ft_putfloat(f, p->precision);
	ft_putstr(tmp);
}
