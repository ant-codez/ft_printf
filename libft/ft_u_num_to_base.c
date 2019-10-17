/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_num_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:51:50 by achavez           #+#    #+#             */
/*   Updated: 2019/09/05 19:51:54 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

uintmax_t     ft_u_num_to_base(uintmax_t num, int base)
{
    uintmax_t         temp[4200];
    int         i;
    int         j;
    uintmax_t   rtn;

    if (num == 0 || num == 10)
        return (num);
    i = 0;
    while (num != 0)
    {
        temp[i] = num % base;
        //printf("Octal[%d] = [%i]\n", i , octal[i]);
        i++;
        num /= base;
    }
    j = i - 1;
    rtn = 0;
    while(j >= 0)
    {
        rtn *= 10;
        rtn += temp[j];
        //printf("octal[%d] rtn[%d] = [%ju]\n",octal[j], j, rtn);
        j--;
    }
    //printf("RETURN = [%ju]\n", rtn);
    return (rtn);
}