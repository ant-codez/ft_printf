/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:22:50 by achavez           #+#    #+#             */
/*   Updated: 2019/04/25 14:46:17 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double  ft_ln(double x)
{
    double old_sum = 0.0;
    double xmlxpl = (x - 1) / (x + 1);
    double xmlxpl_2 = xmlxpl * xmlxpl;
    double denom = 1.0;
    double frac = xmlxpl;
    double term = frac;                 // denom start from 1.0
    double sum = term;

    while ( sum != old_sum )
    {
        old_sum = sum;
        denom += 2.0;
        frac *= xmlxpl_2;
        sum += frac / denom;
    }
    return 2.0 * sum;
}