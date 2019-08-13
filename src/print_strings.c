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
#include <stdio.h>

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