/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:11:50 by achavez           #+#    #+#             */
/*   Updated: 2019/03/09 19:16:11 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
void	check_width(t_data *p)
{
	
}
*/

void	check_flags(t_data *p)
{
	int i = 0;

	while (i < 5)
	{
		if (*p->traverse == '#')
		{
			p->flags[i] = '#';
			p->traverse++;
		}
		else if (*p->traverse == '+')
		{
			p->flags[i] = '+';
			p->traverse++;
		}
		else if (*p->traverse == '-')
		{
			p->flags[i] = '-';
			p->traverse++;
		}
		else if (*p->traverse == '0')
		{
			p->flags[i] = '0';
			p->traverse++;
		}
		else if (*p->traverse == ' ')
		{
			p->flags[i] = ' ';
			p->traverse++;
		}
		i++;
	}
}
