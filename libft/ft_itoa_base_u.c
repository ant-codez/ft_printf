/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:35:43 by achavez           #+#    #+#             */
/*   Updated: 2019/04/25 15:43:40 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base_u(unsigned int value, int base)
{
	char			*s;
	unsigned int	num;
	int				sign;
	int				i;

	num = value;
	sign = base == 10 ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((num /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	num = value;
	while (i-- + sign)
	{
		s[i] = (num % base < 10) ? num % base + '0' : num % base + 'A' - 10;
		num /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
