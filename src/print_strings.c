/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:04:13 by achavez           #+#    #+#             */
/*   Updated: 2019/04/22 20:29:48 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(char *s, t_data *p)
{
	char	*pre;
	int		width;

	width = 0;
	if (p->precision < (int)ft_strlen(s))
		pre = handle_precision(p->precision, s);
	if (p->width > (int)ft_strlen(s))
	{
		width = 1;
		if (p->precision ==  0)
			p->str = handle_width(s, p);
		else
			p->str = handle_width(pre, p);
	}	
	if (width == 1)
		ft_putstr(p->str);
	else if (width == 0 && p->precision != 0)
		ft_putstr(pre);
	else
		ft_putstr(s);
}

char	*handle_width(char *str, t_data *p)
{
	char	*tmp;
	char	*buff;
	int		i;

	buff = ft_strnew(p->width);
	i = -1;
	while (++i != (p->width - (int)ft_strlen(str)))
		p->flags[0] == '0' ? buff[i] = '0' : (buff[i] = ' ');
	if (p->flags[3] == '-')
		tmp = ft_strjoin(str, buff);
	else
		tmp = ft_strjoin(buff, str);
	return (tmp);
}
char	*handle_precision(int precision, char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strnew(precision);
	while(++i != precision)
		tmp[i] = str[i];
	return (tmp);
}
