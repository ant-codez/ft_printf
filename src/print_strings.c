/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:04:13 by achavez           #+#    #+#             */
/*   Updated: 2019/03/19 20:37:24 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(char *s, t_data *p)
{
	int len;

	len = ft_strlen(s);
	if (p->precision < len)
	{
		while (p->precision > 0)
		{
			ft_putchar(*s);
			p->precision--;
			s++;
		}
	}
	else
		ft_putstr(s);
	if (p->width > len && p->flags[3] == '-')
	{
			ft_putstr(s);
			while (p->width > len)
			{
				ft_putchar(' ');
				p->width--;
			}
	}
	else if (p->width > len)
	{
		while (p->width > len)
		{
			p->flags[0] != '0' ? ft_putchar(' ') : ft_putchar('0');
			p->width--;
		}
		ft_putstr(s);
	}
}
