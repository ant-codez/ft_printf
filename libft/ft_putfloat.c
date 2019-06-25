/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:22:50 by achavez           #+#    #+#             */
/*   Updated: 2019/04/25 14:46:17 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long double		f_precision(int p)
{
	long double d;

	d = 1;
	if (p <= 0)
	{
		if (p == -1)
			p = 6;
		else if (p == 0)
			return(0);
	}
	if (p > 0)
	{
		while (--p >= 0)
			d *= 10;
	}
	return (d); 
}

char	*ft_putfloat(long double n, int p)
{
	long long		decimal;
	long double		d;
	long long 		num;
	char			*tmp;

	tmp = ft_strnew(42);
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	d = 1;
	num = (long long)n;
	tmp = ft_strjoin(tmp, ft_itoa_u(num));
	n -= num;
	d = f_precision(p);
	n *= d;
	decimal = (long long)(n + 0.5);
	if (d > 0)
	{
		tmp = ft_strjoin(tmp, ".");
		tmp = ft_strjoin(tmp, ft_itoa_u(decimal));
	}
	return (tmp);
}