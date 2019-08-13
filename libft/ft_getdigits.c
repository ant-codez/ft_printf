/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:45:20 by achavez           #+#    #+#             */
/*   Updated: 2019/03/24 15:50:48 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getdigits(intmax_t num)
{
	int digits;

	digits = 1;
	if (num < 0)
		num *= -1;
	while (num > 9)
		{
			num /= 10;
			digits++;
		}
	return (digits);
}
