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

char	*handle_precision_int(char *str, int pad)
{
	int 	i;
	char	*tmp;
	char	*out;
	char	t;

	tmp = ft_strnew(pad);
	i = -1;
	while (++i != pad)
		tmp[i] = '0';
	out = ft_strjoin(tmp, str);
	i = -1;

	while (out[++i] != '\0')
		if ((out[i] == '-' || out[i] == '+'))
		{
			t = out[i];
			out[i] = '0';
			out[0] = t;
		}
	return (out);
}

char	*handle_width_int(char *str, t_data *p)
{
	char 	*buff;
	char 	*tmp;
	int		i;

	i = -1;
	buff = ft_strnew(p->width);
	while (++i != (p->width - (int)ft_strlen(str)))
		p->flags[0] == '0' ? buff[i] = '0' : (buff[i] = ' ');
	if (p->flags[3] == '-')
		tmp = ft_strjoin(str, buff);
	else
		tmp = ft_strjoin(buff, str);
	return (tmp);
}
