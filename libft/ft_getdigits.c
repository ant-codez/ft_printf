/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:45:20 by achavez           #+#    #+#             */
/*   Updated: 2019/03/22 17:08:50 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getdigits(int num)
{
	int digits;

	digits = 1;
	if (num / 10 > 9)
		while (num / 10 >= 10)
			digits++;
	return (digits);
}
