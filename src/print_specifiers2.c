/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:11:56 by achavez           #+#    #+#             */
/*   Updated: 2019/04/25 15:44:30 by achavez          ###   ########.fr       */
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

void	print_c(t_data *p)
{
	int		c;

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
	uintmax_t 		u;
	char			*s;
	char			*tmp;

	u = oux_length(p);
	s = ft_itoa_u(u);
	if (p->precision > (int)ft_strlen(s))
		tmp = handle_precision_int(s, p->precision - (int)ft_strlen(s));
	if (p->width > (int)ft_strlen(s))
	{
		if (tmp[0] != '\0')
			tmp = handle_width_int(tmp, p);
		else
			tmp = handle_width_int(s, p);
	}
	if (tmp[0] != '\0')
		ft_putstr(tmp);
	else
		ft_putstr(s);
	tmp[0] != '\0' ? p->reee = (int)ft_strlen(tmp) : (p->reee = (int)ft_strlen(s));
}
