/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:02:06 by achavez           #+#    #+#             */
/*   Updated: 2019/08/18 18:09:54 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
	char 	*str = "Hello";
	char 	*col = "Blakkk";
	char	c = 'F';
	unsigned int	u = 3410000000;
	int			num = 124221;
	float		f = 42.42;
	long double ld = 12334234234.4134135412;
	unsigned long long 	ullmax = 9223372036854775807;


	printf("PF = [%#.5x]\n", 34);

	ft_printf("FT = [%#.5x]\n", 34);
	return 0;
}
