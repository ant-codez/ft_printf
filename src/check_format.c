/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:11:50 by achavez           #+#    #+#             */
/*   Updated: 2019/03/13 19:34:45 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_flags(t_data *p)
{
	if (*p->traverse == '#')
		p->flags[1] = '#';
	else if (*p->traverse == '0')
		p->flags[0] = '0';
	else if (*p->traverse == '+')
		p->flags[2] = '+';
	else if (*p->traverse == '-')
		p->flags[3] = '-';
	else if (*p->traverse == ' ')
		p->flags[4] = ' ';
}

void	parse_conversion(t_data *p)
{
	if (*p->traverse == 'h')
		p->length = h;
	if (*p->traverse == 'l')
		p->length = l;
}

void	find_conversions(t_data *p)
{
	while ((ft_strchr_c("#0-+ .123456789hljz", *p->traverse)))
	{
		(ft_strchr_c("#0-+ ", *p->traverse) ? parse_flags(p) : 0);
		if (ft_strchr_c("123456789", *p->traverse))
		{
			p->width = ft_atoi(p->traverse);
		}
		if (*p->traverse == '.' && (p->traverse)++)
		{
			p->precision = ft_atoi(p->traverse);
		}
		(ft_strchr_c("hljz", *p->traverse)) ? parse_conversion(p) : 0;
		p->traverse++;
	}
}
