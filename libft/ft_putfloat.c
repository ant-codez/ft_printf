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

double ft_pow(int base, int exp)
    {
      if(exp < 0)
        return -1;

        double result = 1.0;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }

        return result;
    }

void ft_reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
}

int ft_decimal_str(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
  
    // If number of digits required is more, then 
    // add 0s at the beginning 
    while (i < d) 
        str[i++] = '0'; 
  
    ft_reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 

long long ft_calculate_decimal(long double n, int p)
{
	long long 	decimal;
	long long	d2;
	int			i;
	char		*str;
	char		test[99];

	i = 0;
	d2 = 0;
	n *= (long long)ft_pow(10, p);
	decimal = (long long)(n + 0.5);
	str = ft_itoa((int)decimal);
	//printf("str = [%s]\n", str);

	while(p > 0)
	{
		test[i] = str[i];
		d2 += (ft_atoi(&test[i]) * ft_pow(10, (p - 1)));
		//printf(" p = [%d] d2 = [%lld] test[%d] = [%d]\n",p, d2, i, ft_atoi(&test[i]));
		i++;
		p--;
	}

	return (d2);
}

char	*ft_putfloat(long double n, int precision)
{
	long long		decimal;
	long long 		num;
	int				p;
	char			*dstr;
	char			*tmp;

	tmp = ft_strnew(42);
	dstr = ft_strnew(42);
	precision == -1 ? p = 6 : (p = precision);
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	num = (long long)n;
	n -= num;
	tmp = ft_strjoin(tmp, ft_itoa(num));
	decimal = ft_calculate_decimal(n,p);
	//printf("p = [%i] n = [%Lf] num = [%lld] decimal = [%lld] tmp = [%s]",p, n, num, decimal, tmp);
	if (p != 0)
	{
		tmp = ft_strjoin(tmp, ".");
		ft_decimal_str(decimal, dstr, p);
		tmp = ft_strjoin(tmp, dstr);
	}
	return (tmp);
}