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

//Try and model behavior after width for str : handles only signed ints
void	handle_precision_intV2(intmax_t num, t_data *p)
{
	int 	i;
	int		overflow;

	i = 0;
	overflow = p->precision - ft_getdigits(num);
	if (overflow > 0 && p->precision != -1)
		while(overflow-- > 0)
			ft_putnbr(0);
}

//Version 2.0 for di width
void	handle_width_intV2(int neg, intmax_t num, t_data *p)
{
	int		i;
	int		length;

	i = -1;
	if (p->width > p->precision && p->precision != -1)
		p->precision > ft_getdigits(num) ? length = p->width - p->precision :
		(length = p->width - ft_getdigits(num)); 
	else
		length = p->width - ft_getdigits(num);
	if (neg == 1 || (neg == 0 && p->flags[2] == '+') || (neg == 0 && p->flags[4] == ' '))
		length--;
	if (p->precision == -2 || p->precision == 0)
		length++;
	//printf("length = [%d]\n", length);
	//printf("precision = [%d]\n", p->precision);
	while (++i != length)
		if (p->precision < p->width && p->flags[0] == '0' && p->precision != -1)
			ft_putchar(' ');
		else
			p->flags[0] == '0' ? ft_putchar('0') : ft_putchar(' ');
}

//Try and model behavior after width for str : handles only signed ints
void	handle_u_precision_intV2(uintmax_t num, t_data *p)
{
	int 	i;
	int		overflow;

	i = 0;
	overflow = p->precision - ft_getdigits(num);
	if (p->flags[1] == '#' && (int)num != 0)
		overflow--;
	if (overflow > 0 && p->precision != -1)
		while(overflow-- > 0)
			ft_putnbr(0);
}

//Version 2.0 for di width
void	handle_u_width_intV2(uintmax_t num, t_data *p)
{
	int		i;
	int		length;

	i = -1;
	if (p->width > p->precision && p->precision != -1)
		p->precision > ft_getdigits(num) ? length = p->width - p->precision :
		(length = p->width - ft_getdigits(num)); 
	else
		length = p->width - ft_getdigits(num);
	//printf("FIR length = [%d]\n", length);
	//printf("num = [%ju]\n", num);
	if (p->flags[2] == '+' || p->flags[4] == ' ' || (p->flags[1] == '#' && (num != 0 || p->precision == 0 || p->precision == -2)))
		length--;
	if (p->flags[1] == '#' && (p->precision > ft_getdigits(num)) && num != 0)
		length++;
	if (p->precision == -2 || p->precision == 0)
		length++;
	//printf("FIN length = [%d]\n", length);
	//printf("precision = [%d]\n", p->precision);
	while (++i != length)
		if (p->precision < p->width && p->flags[0] == '0' && p->precision != -1)
			ft_putchar(' ');
		else
			p->flags[0] == '0' ? ft_putchar('0') : ft_putchar(' ');
}

//handle printing out -/+/' '
void	print_symbols(t_data *p, int neg, int num)
{
	if (neg == 0 && p->flags[2] == '+')
		ft_putchar('+');
	else if ((p->flags[1] == '#' && (p->precision == -2 || p->precision == 0)) || (p->flags[1] == '#' && num != 0))
		ft_putchar('0');
	else if (neg == 1)
		ft_putchar('-');
	else if (p->flags[4] == ' ' && neg != 1 && p->flags[2] != '+')
		ft_putchar(' ');
}

char	*handle_precision(int precision, char *str)
{
	char	*tmp;
	int		i;

	if (precision == -1)
		return(NULL);
	else if (precision == -2)
		return("");
	else
		i = -1;
	tmp = ft_strnew(42);
	while(++i != precision)
		tmp[i] = str[i];
	return (tmp);
}

//Version 1 for di int
char	*handle_precision_int(t_data *p, char *str)
{
	int 	i;
	int		len;
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
	len = (int)ft_strlen(str);
	if (str[0] == '+' || str[0] == '-')
		len--;
	while (++i != (p->precision - len))
		tmp[i] = '0';
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}

//Version 1 for di width
char	*handle_width_int(char *str, t_data *p)
{
	char 	*buff;
	char 	*tmp;
	int		i;

	i = -1;
	buff = ft_strnew(p->width);
	//printf("precision = [%d]\n", p->precision);
	while (++i != (p->width - (int)ft_strlen(str)))
	{
		if (p->precision < p->width && p->precision != -1)
			buff[i] = ' ';
		else
			p->flags[0] == '0' && p->width  ? buff[i] = '0' : (buff[i] = ' ');	
	}
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

