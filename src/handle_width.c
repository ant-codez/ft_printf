/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:57:16 by achavez           #+#    #+#             */
/*   Updated: 2019/06/29 15:24:13 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

	if (precision == -1 || precision == 0)
		return("");
	else
		i = -1;
	tmp = ft_strnew(42);
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
	p->flags[2] == '+' ? p->width-- : 0;
	buff = ft_strnew(p->width);
	while (++i != (p->width - (int)ft_strlen(str)))
		p->flags[0] == '0' ? buff[i] = '0' : (buff[i] = ' ');
	p->flags[2] == '+' ? str = ft_strjoin("+", str) : 0;
	if (p->flags[3] == '-')
		tmp = ft_strjoin(str, buff);
	else
		tmp = ft_strjoin(buff, str);
	return (tmp);
}
