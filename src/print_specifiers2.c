/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:11:56 by achavez           #+#    #+#             */
/*   Updated: 2019/03/19 21:32:40 by achavez          ###   ########.fr       */
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
	ft_putstr(p->str);
}

void	print_c(t_data *p)
{
	int		c;

	c = va_arg(p->arg, int);
	if (p->width > 1 && p->flags[3] == '-')
	{
		ft_putchar(c);
		while (p->width > 0)
		{
			ft_putchar(' ');
			p->width--;
		}
	}
	else
	{
		while (p->width > 0)
		{
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
			p->width--;
		}
		ft_putchar(c);
	}
}
