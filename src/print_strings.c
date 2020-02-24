/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:04:13 by achavez           #+#    #+#             */
/*   Updated: 2020/02/23 17:38:51 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(char *s, t_data *p)
{
	char	*pre;

	pre = handle_precision(p->precision, s);
	if (p->width > 0)
	{
		if (p->precision == -1)
			pre = handle_width(s, p);
		else
			pre = handle_width(pre, p);
	}
	if (pre == NULL)
		ft_putstr(s);
	else
		ft_putstr(pre);
}
