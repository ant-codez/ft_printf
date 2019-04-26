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

char	*ft_putfloat(double n, int p)
{
	signed long int	decimal;
	int				d;
	signed long int num;
	char			*tmp;

	tmp = ft_strnew(42);
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	d = 1;
	num = (signed long int)n;
	tmp = ft_strjoin(tmp, ft_itoa_u(num));
	tmp = ft_strjoin(tmp, ".");
	n -= num;

	if (p > 0)
		while (--p >= 0)
			d *= 10;
	else
		d = 1000000;

	n *= d;
	decimal = (signed long int)(n + 0.5);
	tmp = ft_strjoin(tmp, ft_itoa_u(decimal));
	return (tmp);
}
