/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:04:13 by achavez           #+#    #+#             */
/*   Updated: 2019/04/25 20:08:45 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(char *s, t_data *p)
{
	char	*pre;

	pre = ft_strnew(p->precision);
	if (p->precision < (int)ft_strlen(s))
		pre = handle_precision(p->precision, s);
	if (p->width > (int)ft_strlen(s))
	{
		if (p->precision ==  0)
			pre = handle_width(s, p);
		else
			pre = handle_width(pre, p);
	}
	if (pre[0] != '\0')
		ft_putstr(pre);
	else
		ft_putstr(s);
	pre[0] != '\0' ? p->reee = (int)ft_strlen(pre) : (p->reee = (int)ft_strlen(s));
}