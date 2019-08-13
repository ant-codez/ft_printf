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

	if (p->width < (int)ft_strlen(str))
		return (str);
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

	if (precision == -1)
		return(NULL);
	else if (precision == 0)
		return("");
	else
		i = -1;
	tmp = ft_strnew(42);
	while(++i != precision)
		tmp[i] = str[i];
	return (tmp);
}

char	*handle_precision_int(t_data *p, char *str)
{
	int 	i;
	char	*tmp;

	if (p->precision < (int)ft_strlen(str))
		return (str);
	if (p->precision == -1)
		return(NULL);
	else if (p->precision == 0)
		return("");
	else
		i = -1;
	tmp = ft_strnew(42);
	while (++i != (p->precision - (int)ft_strlen(str)))
		tmp[i] = '0';
	tmp = ft_strjoin(tmp, str);
	return (tmp);
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

char	*handle_swap(char *str, t_data *p)
{
	char	t;
	int		i;

	p->precision = 0;

	i = -1;
	while (str[++i] != '\0')
		if ((str[i] == '-' || str[i] == '+') && p->flags[0] == '0')
		{
			t = str[i];
			str[i] = str[0];
			str[0] = t;
		}
	return (str);
}
