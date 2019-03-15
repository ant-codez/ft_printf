/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:49:35 by achavez           #+#    #+#             */
/*   Updated: 2019/03/15 16:30:45 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_o(t_data *p)
{
	int 	o;
	char	*str;

	o = va_arg(p->arg, int);
	str = ft_itoa_base(o, 8);
	if (p->flags[1] == '#')
	{
		p->str = ft_strjoin("0", str);
		ft_putstr(p->str);
	}
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

void	print_f(t_data *p)
{
	double f;

	f = va_arg(p->arg, double);
	ft_putfloat(f);
}
